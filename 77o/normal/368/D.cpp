#include <bits/stdc++.h>
#define int long long
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int random(int st, int dr)
{
    uniform_int_distribution<mt19937::result_type> gen(st, dr);
    return gen(rng);
}
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int32_t main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
    }
    vector<int> norm = b;
    sort(norm.begin()+1, norm.end());
    map<int, int> f;
    for (int i = 1; i <= m; ++i)
    {
        f[norm[i]];
        f[norm[i]] = f.size();
    }
    for (int i = 1; i <= m; ++i)
    {
        b[i] = f[b[i]];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (f.find(a[i]) == f.end())
        {
            a[i] = m + 1;
        }
        else
        {
            a[i] = f[a[i]];
        }
    }
    map<int, int> frecv;
    for (int i = 1; i <= m; ++i)
    {
        frecv[b[i]]++;
    }
    frecv[m+1]=0;
    vector<vector<pair<int,int>>> clase(p, vector<pair<int,int>>(1));
    for (int i = 1; i <= n; ++i)
    {
        clase[i % p].push_back({a[i],i});
    }
    int need = frecv.size();
    vector<int> ans;
    for (int i = 0; i < p; ++i)
    {
        int sz = clase[i].size()-1;
        if (sz >= m)
        {
            map<int, int> f;
            int cnt = 1;
            function<void(int)> inc = [&](int val)
            {
                if (f[val] == frecv[val])
                {
                    cnt--;
                }
                f[val]++;
                if (f[val] == frecv[val])
                {
                    cnt++;
                }
            };
            function<void(int)> dec = [&](int val)
            {
                if (f[val] == frecv[val])
                {
                    cnt--;
                }
                f[val]--;
                if (f[val] == frecv[val])
                {
                    cnt++;
                }
            };
            for (int j = 1; j <= m; ++j)
            {
                inc(clase[i][j].first);
            }
            if (cnt == need)
            {
                
                ans.push_back(clase[i][1].second);
            }
            for (int j = m + 1; j <= sz; ++j)
            {
                dec(clase[i][j - m].first);
                inc(clase[i][j].first);
                if (cnt == need)
                {
                    ans.push_back(clase[i][j - m + 1].second);
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto i : ans){
        cout<<i<<' ';
    }
}