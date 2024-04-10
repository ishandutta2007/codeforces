#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 2e5 + 10;
int n, m;
vi event[N];
multiset<int> suffix[2], active[2];
ll Sum[2][N], Cnt[2][N];

void add(ll bit[], int pos, ll val)
{
    for (int i = pos; i <= m; i += (i & -i)) bit[i] += val;
}

ll get(ll bit[], int pos)
{
    ll res = 0;
    for (int i = pos; i; i -= (i & -i)) res += bit[i];
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1, l, r; i <= n; ++i)
    {
        cin >> l >> r;
        event[l].eb(l);
        event[r + 1].eb(-l);
    }
    int near = 0;
    ll res = 0;
    for (int i = 1; i <= m; ++i)
    {
        int p = i & 1;
        for (int x : event[i])
            if (x > 0) suffix[x & 1].insert(x);
            else
            {
                x = -x;
                suffix[x & 1].erase(suffix[x & 1].find(x));
                if (((i - x) & 1) == 0)
                {
                    for (int j = 0; j <= 1; ++j)
                        while (!active[j].empty() && *(active[j].begin()) <= x)
                        {
                            int tmp = *(active[j].begin());
                            add(Sum[j], tmp, -tmp + 1);
                            add(Cnt[j], tmp, -1);
                            active[j].erase(active[j].begin());
                        }
                }
                while (!active[p].empty() && *(prev(active[p].end())) >= x)
                {
                    int tmp = *(prev(active[p].end()));
                    add(Sum[p], tmp, -tmp + 1);
                    add(Cnt[p], tmp, -1);
                    active[p].erase(prev(active[p].end()));
                }
                near = i - 1;
            }
        active[p].insert(i);
        add(Sum[p], i, i - 1);
        add(Cnt[p], i, 1);
        int r = i;
        if (suffix[0].empty() && suffix[1].empty())
        {
            if (near == 0) continue;
            r = near;
        }
        if (!suffix[p ^ 1].empty())
        {
            int l = *(prev(suffix[p ^ 1].end()));
            if (l < r) res += (get(Cnt[p], r) - get(Cnt[p], l)) * i - get(Sum[p], r) + get(Sum[p], l);
        }
        else
        {
            if (suffix[p].empty())
                res += (get(Cnt[0], r) + get(Cnt[1], r)) * i - get(Sum[0], r) - get(Sum[1], r);
            else
            {
                int mid = *(suffix[p].begin());
                if (mid <= r) res += (get(Cnt[p], r) - get(Cnt[p], mid - 1)) * i - get(Sum[p], r) + get(Sum[p], mid - 1);
                r = min(r, mid - 1);
                res += (get(Cnt[0], r) + get(Cnt[1], r)) * i - get(Sum[0], r) - get(Sum[1], r);
            }
        }
    }
    cout << res;
    return 0;
}