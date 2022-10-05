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
vector<vector<bool>> f;
vector<vector<ll>> r, c, mostu, mostl, dpl, dpu, dp, pdpl, pdpu;
bool viv = false;


int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f.resize(n);
    for (auto &l : f)
        l.resize(m, 0);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'R')
                f[i][j] = 1;
        }
    }
    r.resize(n);
    c.resize(m);
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--)
            if (f[i][j])
                r[i].push_back(j),
                c[j].push_back(i);
    }
    mostl.resize(n);
    for (auto &l : mostl)
        l.resize(m, -1);
    mostu.resize(n);
    for (auto &l : mostu)
        l.resize(m, -1);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            ll str = m-1-j;
            ll stc = n-1-i;
            if (r[i].size() > str)
                mostl[i][j] = r[i][str];
            if (c[j].size() > stc)
                mostu[i][j] = c[j][stc];
            if (viv)
                cout << "{ " << mostl[i][j] << ' ' << mostu[i][j] << "}, ";
        }
        if (viv)
            cout << endl;
    }

    dp.resize(n);
    for (auto &l : dp)
        l.resize(m);
    dpl.resize(n);
    for (auto &l : dpl)
        l.resize(m);
    dpu.resize(n);
    for (auto &l : dpu)
        l.resize(m);
    pdpl.resize(n+1);
    for (auto &l : pdpl)
        l.resize(m+1);
    pdpu.resize(n+1);
    for (auto &l : pdpu)
        l.resize(m+1);

    dpl[0][0] = 1;
    dpu[0][0] = 1;
    pdpu[0][1] = 1;
    pdpl[1][0] = 1;
    dp[0][0] = 1;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (j > 0) {
                dpl[i][j] += pdpu[i][j];
                if (mostl[i][j] != -1)
                    dpl[i][j] -= pdpu[i][mostl[i][j]];
                dpl[i][j] %= mod;
            }
            if (i > 0) {
                dpu[i][j] += pdpl[i][j];
                if (mostu[i][j] != -1)
                    dpu[i][j] -= pdpl[mostu[i][j]][j];
                dpu[i][j] %= mod;
            }
            pdpl[i+1][j] = pdpl[i][j] + dpl[i][j];
            pdpl[i+1][j] %= mod;
            pdpu[i][j+1] = pdpu[i][j] + dpu[i][j];
            pdpu[i][j+1] %= mod;
            if (i + j != 0)
                dp[i][j] = (dpl[i][j] + dpu[i][j]) % mod;
            if (dp[i][j] < 0)
                dp[i][j] += mod;
            if (viv)
                cout << dp[i][j] << ' ' << dpl[i][j] << ' ' << dpu[i][j] << ';' << ' ';
        }
        if (viv)
            cout << endl;
    }

    cout << dp[n-1][m-1] << endl;


    return 0;
}
/**
40 40
.R......................................
R.......................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................


4 4
..R.
.RRR
RR..
R.R.





**/