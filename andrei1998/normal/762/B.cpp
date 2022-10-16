#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector <int> t1;
vector <int> t2;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int m = 0;
    cin >> m;

    while (m --) {
        int x;
        cin >> x;

        string str;
        cin >> str;

        if (str == "USB")
            t1.push_back(x);
        else
            t2.push_back(x);
    }

    int cnt = 0;
    long long int ans = 0;

    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    reverse(t1.begin(), t1.end());
    reverse(t2.begin(), t2.end());

    while (a > 0 && t1.size()) {
        a --;
        cnt ++;
        ans += t1.back();
        t1.pop_back();
    }

    while (b > 0 && t2.size()) {
        b --;
        cnt ++;
        ans += t2.back();
        t2.pop_back();
    }

    vector <int> t;
    for (auto it: t1)
        t.push_back(it);
    for (auto it: t2)
        t.push_back(it);

    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());

    while (c > 0 && t.size()) {
        c --;
        cnt ++;
        ans += t.back();
        t.pop_back();
    }

    cout << cnt << ' ' << ans << '\n';
    return 0;
}