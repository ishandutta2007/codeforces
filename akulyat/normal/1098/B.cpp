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


ll n, i, j, m;
vector<vector<ll>> f;
vector<ll> r[4][4], c[4][4];
ll ans[2][4][4];
map<char, ll> mp;
map<ll, char> omp;
bool viv = false;

void count_c(ll cn, ll b1, ll b2) {
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        if (i & 1) {
            if (f[i][cn] != b2)
                res++;
        } else {
            if (f[i][cn] != b1)
                res++;
        }
    }
    c[b1][b2].push_back(res);
}

void count_r(ll rn, ll b1, ll b2) {
    ll res = 0;
    for (ll i = 0; i < m; i++) {
        if (i & 1) {
            if (f[rn][i] != b2)
                res++;
        } else {
            if (f[rn][i] != b1)
                res++;
        }
    }
    r[b1][b2].push_back(res);
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    mp['A'] = 0;
    mp['C'] = 1;
    mp['T'] = 2;
    mp['G'] = 3;
    omp[0] = 'A';
    omp[1] = 'C';
    omp[2] = 'T';
    omp[3] = 'G';
    f.resize(n);
    for (i = 0; i < n; i++) {
        f[i].resize(m);
        string s;
        cin >> s;
        for (ll j = 0; j < m; j++) {
            f[i][j] = mp[s[j]];
        }
    }

    for (ll i = 0; i < m; i++)
        for (ll j = 0; j < 4; j++)
            for (ll u = 0; u < 4; u++)
                if (j != u)
                    count_c(i, j, u);
    if (viv)
        cout << "Counted c" << endl;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < 4; j++)
            for (ll u = 0; u < 4; u++)
                if (j != u)
                    count_r(i, j, u);
    if (viv)
        cout << "Counted r" << endl;
    for (ll u = 0; u < 2; u++)
        for (ll i = 0; i < 4; i++)
            for (ll j = 0; j < 4; j++)
                if (i != j) {
                    if (u == 0) {
                        ll a = 0, b = 0;
                        while (a == i || a == j)
                            a++;
                        while (b == i || b == j || b == a)
                            b++;
                        for (ll z = 0; z < m; z++)
                            if (z & 1)
                                ans[u][i][j] += min(c[a][b][z], c[b][a][z]);
                            else
                                ans[u][i][j] += min(c[i][j][z], c[j][i][z]);
                    } else {
                        ll a = 0, b = 0;
                        while (a == i || a == j)
                            a++;
                        while (b == i || b == j || b == a)
                            b++;
                        for (ll z = 0; z < n; z++)
                            if (z & 1)
                                ans[u][i][j] += min(r[a][b][z], r[b][a][z]);
                            else
                                ans[u][i][j] += min(r[i][j][z], r[j][i][z]);
                    }
                }
    if (viv)
        cout << "ans ready " << endl;
    vector<ll> w = {0, 0, 1};
    for (ll u = 0; u < 2; u++)
        for (ll i = 0; i < 4; i++)
            for (ll j = 0; j < 4; j++)
                if (i != j) {
                    if (ans[u][i][j] < ans[w[0]][w[1]][w[2]])
                        w = {u, i, j};
                    if (viv)
                        cout << u << ' ' << i << ' ' << j << ": " << ans[u][i][j] << endl;
                }
    if (viv)
        cout << "use " << w[0] << ' ' << w[1] << ' ' << w[2] << endl;
    if (w[0] == 0) {
        for (ll j = 0; j < m; j++) {
            ll a = 0, b = 0;
            while (a == w[1] || a == w[2])
                a++;
            while (b == w[1] || b == w[2] || b == a)
                b++;
            if (c[b][a][j] < c[a][b][j])
                swap(a, b);
            if (c[w[2]][w[1]][j] < c[w[1]][w[2]][j])
                swap(w[1], w[2]);
            if (j & 1) {
                for (ll i = 0; i < n; i++)
                    if (i & 1)
                        f[i][j] = omp[b];
                    else
                        f[i][j] = omp[a];
            } else {
                for (ll i = 0; i < n; i++)
                    if (i & 1)
                        f[i][j] = omp[w[2]];
                    else
                        f[i][j] = omp[w[1]];
            }
        }
    }
    if (w[0] == 1) {
        for (ll j = 0; j < n; j++) {
            ll a = 0, b = 0;
            while (a == w[1] || a == w[2])
                a++;
            while (b == w[1] || b == w[2] || b == a)
                b++;
            if (r[b][a][j] < r[a][b][j])
                swap(a, b);
            if (r[w[2]][w[1]][j] < r[w[1]][w[2]][j])
                swap(w[1], w[2]);
            if (j & 1) {
                for (ll i = 0; i < m; i++)
                    if (i & 1)
                        f[j][i] = omp[b];
                    else
                        f[j][i] = omp[a];
            } else {
                for (ll i = 0; i < m; i++)
                    if (i & 1)
                        f[j][i] = omp[w[2]];
                    else
                        f[j][i] = omp[w[1]];
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
            cout << char(f[i][j]);
        cout << endl;
    }

    return 0;
}
/**
3 2
AG
TC
GA

2 3
ATG
GCA






**/