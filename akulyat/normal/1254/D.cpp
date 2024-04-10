#include <bits/stdc++.h>

#pragma GCC optimize("O3", "unroll-all-loops")
#pragma GCC target("avx2")

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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7;
const long long gs = 151 * kk;
const int S = 800;


ll n, m, i, j, q, sum, obrn, tc;
vector<int> reb[gs + 10];
vector<int> col;
vector<vector<int>> kids;
vector<int> p, sz;
vector<ll> qr, ans;
vector<pll> all;
vector<vector<int>> par;
bool viv = false;

void DFS(ll v, ll c) {
    col[v] = c;
    ll l = reb[v].size();
    sz[v] = 1;
    for (ll i = 0; i < l; i++) {
        ll s = reb[v][i];
        if (col[s] == -1) {
            DFS(s, c + 1), kids[v].push_back(s), p[s] = v, sz[v] += sz[s];
        }
    }
}

long long obr(long long v, long long mod)
{
long long i = 0;
long long st = mod - 2;
vector<long long> bin;
long long l = 0;
while(st > 0)
    {
    bin.push_back(st & 1);
    st /= 2;
    l++;
    }

vector<long long> sq;
sq.push_back(v);
for (i = 1; i < l; i++)
    {
    long long s = sq.back();
    s *= s;
    s %= mod;
    sq.push_back(s);
    }

long long ans = 1;
for (i = 0; i < l; i++)
    if (bin[i])
        {
        ans *= sq[i];
        ans %= mod;
        }
return ans;
}

ll frac(ll val, ll nom, ll den) {
    val *= nom;
    val %= mod;
//    val *= obr(den, mod);
    val *= den;
    val %= mod;
    if (val < 0)
        val += mod;
    return val;
}

void prepare() {
    par.resize(19);
    par[0] = p;
    for (int j = 1; j < par.size(); j++) {
        par[j].resize(n);
        for (int i = 0; i < n; i++)
            par[j][i] = par[j-1][par[j-1][i]];
    }
}

int pp(int v, int ups) {
    for (int j = 0; j < 20; j++) {
        if (ups & 1)
            v = par[j][v];
        ups >>= 1;
    }
    return v;
}


void DFS2(int v, int c, ll msum) {
    ans[v] += sum;
    ans[v] += msum;
    ans[v] -= frac(qr[v], sz[v], obrn);
    ans[v] %= mod;
    for (auto s : kids[v]) {
        ll lsum = msum;
//        lsum -= frac(qr[v], sz[v], obrn);
        lsum += frac(qr[v], n - sz[s] - sz[v], obrn);
        if (viv)
            cout << "Add from " << v << " to " << s << " sum = " << lsum << endl;
        DFS2(s, c + 1, lsum);
    }
}

void maker() {
    DFS2(0, 0, 0);
    for (auto &i : qr)
        i = 0;
    if (viv) {
        for (auto i : ans)
            cout << i << ' ';
        cout << endl;
    }
    all.clear();
    sum = 0;
}

void adder() {
    int v, val;
    cin >> v >> val;
    v--;
    ans[v] += val;
    if (ans[v] >= mod)
        ans[v] -= mod;
    sum += frac(val, sz[v], obrn);
    if (sum >= mod)
        sum -= mod;
    qr[v] += val;
    if (qr[v] >= mod)
        qr[v] -= mod;
    all.push_back({v, val});
    if (all.size() >= S)
        maker();
}

void answer() {
    ll v;
    cin >> v;
    v--;
    ll lans = ans[v];
    lans += sum;
    lans -= frac(qr[v], sz[v], obrn);
    ll now = p[v];
    ll kid = v;
    while (kid != 0) {
        lans -= frac(qr[now], sz[now], obrn);
        lans += frac(qr[now], n - sz[kid], obrn);
        now = p[now];
        kid = p[kid];
    }
    lans %= mod;
    if (lans < 0)
        lans += mod;
//    cout << "_______ ";
    cout << lans << '\n';
}

void answer_fast() {
    int v;
    cin >> v;
    v--;
    ll lans = ans[v];
    lans += sum;
    lans -= frac(qr[v], sz[v], obrn);
    for (auto pr : all)
        if (col[pr.F] < col[v]) {
            int kid = pp(v, col[v] - col[pr.F] - 1);
            if (p[kid] == pr.F) {
//                lans -= frac(pr.S, sz[pr.F], obrn);
                lans += frac(pr.S, n - sz[kid] - sz[pr.F], obrn);
            }
        }
    lans %= mod;
    if (lans < 0)
        lans += mod;
//    cout << "_______ ";
    cout << lans << '\n';
}

void solve() {
    short t;
    cin >> t;
    if (t == 1)
        adder();
    if (t == 2)
        answer_fast();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    obrn = obr(n, mod);
    m = n - 1;
    p.resize(n);
    sz.resize(n);
    kids.resize(n);
    ans.resize(n);
    qr.resize(n);
    for (i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;
        a--; b--;
        reb[a].push_back(b);
        reb[b].push_back(a);
    }
    col.assign(n, -1);
    DFS(0, 0);
    p[0] = 0;
    prepare();
    while (q--)
        solve();



    return 0;
}