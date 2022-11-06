#include <bits/stdc++.h>
using namespace std;

vector<long long> arr[15];
vector<pair<int, int>> edg[15];
long long mem[15];

vector<pair<int, int>> cyc[1 << 15];
vector<vector<pair<int, int>>> cmem[1 << 15];

long long pri[15][2];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            long long x;
            scanf("%lld", &x);
            arr[i].push_back(x);
        }
    }

    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(long long x : arr[i])
            mem[i] += x;
        sum += mem[i];
    }

    if(sum % n != 0)
    {
        puts("No");
        return 0;
    }

    sum /= n;

    map<long long, pair<int, int>> mp;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < (int)arr[i].size(); j++)
            mp[arr[i][j]] = { i, j };

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (int)arr[i].size(); j++)
        {
            long long x = arr[i][j];
            long long y = sum - mem[i] + x;
            
            auto it = mp.find(y);
            if(it != mp.end())
                edg[i].push_back(it->second);
            else
                edg[i].push_back({ -1, -1 });
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (int)arr[i].size(); j++)
        {
            int chk = 0;
            bool ok = 1;
            int x1 = i;
            int x2 = j;
            vector<pair<int, int>> res;
            while(1)
            {
                res.push_back({ x1, x2 });
                chk |= 1 << x1;

                int y1, y2;
                tie(y1, y2) = edg[x1][x2];

                if(y1 == i && y2 == j)
                {
                    break;
                }

                if(y1 == -1 || (chk & (1 << y1)))
                {
                    ok = 0;
                    break;
                }

                x1 = y1;
                x2 = y2;
            }
            if(!ok)
                continue;

            if(cyc[chk].empty())
                cyc[chk] = res;
        }
    }

    for(int b = 1; b < (1 << n); b++)
    {
        if(!cyc[b].empty())
        {
            cmem[b].push_back(cyc[b]);
            continue;
        }

        int t = b;
        while(t > 0)
        {
            if(!cmem[t].empty() && !cyc[b ^ t].empty())
            {
                for(auto &v : cmem[t])
                    cmem[b].push_back(v);
                cmem[b].push_back(cyc[b ^ t]);
                break;
            }

            t = (t - 1) & b;
        }
    }

    if(cmem[(1 << n) - 1].empty())
    {
        puts("No");
        return 0;
    }

    puts("Yes");
    for(auto &v : cmem[(1 << n) - 1])
    {
        int sz = (int)v.size();
        for(int i = 0; i < sz; i++)
        {
            int x1, x2;
            tie(x1, x2) = v[i];

            int y1, y2;
            tie(y1, y2) = v[(i + 1) % sz];

            pri[y1][0] = arr[y1][y2];
            pri[y1][1] = x1 + 1;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%lld %lld\n", pri[i][0], pri[i][1]);

    return 0;
}