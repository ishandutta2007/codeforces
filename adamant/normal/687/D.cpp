#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 42;
int par[maxn];
int col[maxn];
vector<int> lst[maxn];
bool uni(int a, int b)
{
    int ta = par[a];
    int tb = par[b];
    int ca = col[a];
    int cb = col[b];
    if(lst[ta].size() < lst[tb].size())
    {
        swap(ta, tb);
        swap(a, b);
        swap(ca, cb);
    }
    if(ta != tb)
    {
        for(auto it: lst[tb])
        {
            if(ca == cb)
                col[it] ^= 1;
            par[it] = ta;
            lst[ta].push_back(it);
        }
        return 1;
    }
    else
    {
        return ca != cb;
    }
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int u[m], v[m], c[m];
    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i] >> c[i];
        u[i]--;
        v[i]--;
    }
    int p[m];
    iota(p, p + m, 0);
    sort(p, p + m, [&](int a, int b){return c[a] > c[b];});
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        for(int i = 0; i < maxn; i++)
        {
            par[i] = i;
            lst[i] = {i};
            col[i] = rand() % 2;
        }
        l--;
        for(int i = 0; i < m; i++)
            if(p[i] >= l && p[i] < r)
            {
                if(!uni(u[p[i]], v[p[i]]))
                {
                    cout << c[p[i]] << "\n";
                    goto nxt;
                }
            }
        cout << -1 << "\n";
        nxt:;
    }
	return 0;
}