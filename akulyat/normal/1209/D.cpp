#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
const long long gs = 500 * kk;

ll n, m, i, j, cnt;
vector<ll> reb[gs + 10];
vector<ll> col, tc;
bool viv = false;

void DFS(ll v, ll c)
{
col[v] = c;
cnt++;
ll l = reb[v].size();
for (ll i = 0; i < l; i++)
    {
    ll s = reb[v][i];
    if (col[s] == -1)
        {
        DFS(s, c  +1);
        }
    }
}

void BFS(ll v)
{
vector<long> st;
st.push_back(v);
ll s = 0;
tc[v] = 0;

while (s < st.size())
    {
    ll e = st[s];
    ll l = reb[e].size();
    for (ll i = 0; i < l; i++)
        {
        ll s = reb[e][i];
        if (tc[s] == -1)
            {
            st.push_back(s);
            tc[s] = tc[e]+1;
            }
        }
    s++;
    }
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin >> n >> m;
for (i = 0; i < m; i++)
    {
    long a, b;
    cin >> a >> b;
    a--; b--;
    reb[a].push_back(b);
    reb[b].push_back(a);
    }
col.assign(n, -1);
tc.assign(n, -1);

ll ans = 0;
cnt = 0;
for (ll i = 0; i < n; i++)
    if (col[i] == -1) {
        DFS(i, 0);
        ans += cnt-1;
        cnt = 0;

    }

ans = m - ans;
cout << ans;







        return 0;
}