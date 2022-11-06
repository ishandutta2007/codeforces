#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

int n, i, s1, s2;
int x[maxN], cnt;
vector<int> ord;
set<int> S;


bool check(int sz) {
    int i;
    bool local;

    S.clear();
    x[0] = s1;
    S.insert(s2);

    for (i = 1; i <= n; i++) {
        int last = x[i - 1];
        int act = x[i];

        while (!S.empty()) {
            auto it = S.begin();
            if (abs(*it - act) <= sz)
                break;
            S.erase(it);
        }

        while (!S.empty()) {
            auto it = S.end(); it--;
            if (abs(*it - act) <= sz)
                break;
            S.erase(it);
        }

        if (abs(act - last) <= sz)
            if (S.find(last) == S.end())
                S.insert(last);

        if (S.empty()) return false;
    }

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> s1 >> s2;
    ord = {s1, s2};
    for (i = 1; i <= n; i++) {
        cin >> x[i];
        ord.pb(x[i]);
    }

    sort(ord.begin(), ord.end());
    ord.resize(unique(ord.begin(), ord.end()) - ord.begin());
    cnt = ord.size();

    int ans = max(s1, s2) - min(s1, s2) - 1;
    for (int step = 1 << 30; step > 0; step >>= 1)
        if (ans + step <= 1000000000)
            if (!check(ans + step))
                ans += step;

    ans++;
    cout << ans;



    return 0;
}