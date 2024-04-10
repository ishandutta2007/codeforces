#include <bits/stdc++.h>
using namespace std;
const int N = 20004;

int t1, t2, t3;
vector<int> a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t1 >> t2 >> t3;
    int k;
    cin >> k;
    while (k--)
    {
        int x;
        string s;
        cin >> x >> s;
        if (s == "USB")
            a.push_back(x);
        else
            b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int ans = 0;
    long long g = 0;
    while (!a.empty() && t1)
    {
        --t1;
        ++ans;
        g += a.back();
        a.pop_back();
    }
    while (!b.empty() && t2)
    {
        --t2;
        ++ans;
        g += b.back();
        b.pop_back();
    }
    for (int i = 0; i < b.size(); ++i)
        a.push_back(b[i]);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    while (!a.empty() && t3)
    {
        --t3;
        ++ans;
        g += a.back();
        a.pop_back();
    }
    cout << ans << ' ' << g << endl;
    return 0;
}