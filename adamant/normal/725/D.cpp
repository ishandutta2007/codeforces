#include <bits/stdc++.h>

using namespace std;
#define int64_t long long
    int64_t t[300000], w[300000];
    int p[300000];
signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    n = 300000;cin >> n;
    for(int i = 0; i < n; i++)
    {
        t[i] = rand();
        w[i] = t[i] + rand();
        cin >> t[i] >> w[i];
    }
    iota(p + 1, p + n, 1);
    sort(p + 1, p + n, [&](int a, int b){return t[a] > t[b];});
    int l = 0, r = n;
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        int64_t tt = t[0];
        set<int, function<bool(int, int)>> lol([&](int a, int b){return make_pair(w[a] - t[a], a) < make_pair(w[b] - t[b], b);});
        int it = 1;
        int ans = n;
        while(true)
        {
            while(it < n && t[p[it]] > t[0])
            {
                lol.insert(p[it]);
                it++;
            }
            ans = min(ans, (int)lol.size() + 1);
            if(lol.empty())
                break;
            auto jt = *lol.begin();
            if(t[0] < w[*lol.begin()] - t[*lol.begin()] + 1)
                break;
            t[0] -= w[*lol.begin()] - t[*lol.begin()] + 1;
            lol.erase(lol.begin());
        }
            ans = min(ans, (int)lol.size() + 1);
        cout << ans << endl;
        return 0;
        t[0] = tt;
        if(lol.size() < m)
            r = m;
        else
            l = m;
    }
    cout << r << endl;
    return 0;
}