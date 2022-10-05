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

ll n, m, i, j, k;
vector<ll> reb[gs + 10];
vector<ll> col, tc, q, w;
vector<vector<ll>> ans;
vector<vector<vector<ll>>> kids;
bool viv = false;

void DFS(ll v, ll c) {
    col[v] = c;
    ll l = reb[v].size();
    for (ll i = 0; i < l; i++) {
        ll s = reb[v][i];
        if (col[s] == -1) {
            DFS(s, c  +1);
        }
    }
    q.push_back(v);
}

void solve(ll v, ll s, ll lev) {
    ll ost = k - lev;
    ost = max(ost, (k+1)/2);
    ost = max(ost, lev);

    ll lans = 0;
    lans += ans[s][lev-1];
    for (auto son : kids[v][1])
        if (son != s)
            lans += ans[son][ost-1];


    if (viv)
        cout << "fooor " << v << ' ' << s << ' ' << lev << " is " << lans << endl;
    ans[v][lev] = max(ans[v][lev], lans);
}

void work(ll v) {
    kids[v].resize(2);
    kids[v][0].push_back(v);
    for (auto s : reb[v])
        if (col[s] > col[v]) {
            for (ll i = 0; i < 1; i++)
                for (auto kk : kids[s][i])
                    kids[v][i+1].push_back(kk);
        }
    ans[v][0] = 0;
    ans[v][0] += w[v];
    for (auto s : kids[v][1]) {
        ans[v][0] += ans[s][k - 1];
    }
    if (viv) {
        cout << "st ans for " << v << " is " << ans[v][0] << endl;
    }

    for (int i = 1; i < k; i++)
        for (auto s : kids[v][1])
            solve(v, s, i);
    for (int i = k - 2; i >= 0; i--)
        ans[v][i] = max(ans[v][i], ans[v][i+1]);
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    k++;
    m = n - 1;
    w.resize(n);
    for (auto &i : w)
        cin >> i;
    for (i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;
        a--; b--;
        reb[a].push_back(b);
        reb[b].push_back(a);
    }
    col.assign(n, -1);
    tc.assign(n, -1);
    DFS(0, 0);

    ans.resize(n);
    for (auto &i : ans)
        i.resize(k, 0);
    kids.resize(n);
    for (auto v : q) {
        work(v);
    }

    cout << ans[0][0] << endl;

    return 0;
}