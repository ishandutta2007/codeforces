#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }
#define ifn(x) if(!(x))

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

char a[510][510];

ll pref_r[510][510];
ll pref_g[510][510];
ll pref_b[510][510];
ll pref_y[510][510];

int pref_good[254][501][501];

ll l, r, l1, r1;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m, q;
    cin >> n >> m >> q;


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'R'){
                pref_r[i][j] = 1;
            }
            if(a[i][j] == 'Y'){
                pref_y[i][j] = 1;
            }
            if(a[i][j] == 'G'){
                pref_g[i][j] = 1;
            }
            if(a[i][j] == 'B'){
                pref_b[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pref_r[i][j] += pref_r[i - 1][j] + pref_r[i][j - 1] - pref_r[i - 1][j - 1];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pref_g[i][j] += pref_g[i - 1][j] + pref_g[i][j - 1] - pref_g[i - 1][j - 1];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pref_b[i][j] += pref_b[i - 1][j] + pref_b[i][j - 1] - pref_b[i - 1][j - 1];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pref_y[i][j] += pref_y[i - 1][j] + pref_y[i][j - 1] - pref_y[i - 1][j - 1];
        }
    }
    for(int len = 1; len <= 250; len++){
        for(int i = 1; i <= n - 2 * len + 1; i++){
            for(int j = 1; j <= m - 2 * len + 1; j++){
                bool ok = 1;
                l = i, r = i + len - 1;
                l1 = j, r1 = j + len - 1;
                ifn(pref_r[r][r1] - pref_r[r][l1 - 1] - pref_r[l - 1][r1] + pref_r[l - 1][l1 - 1] == sqr(len))ok = 0;

                l = i, r = i + len - 1;
                l1 = j + len, r1 = j + 2 * len - 1;
                ifn(pref_g[r][r1] - pref_g[r][l1 - 1] - pref_g[l - 1][r1] + pref_g[l - 1][l1 - 1] == sqr(len))ok = 0;

                l = i + len, r = i + 2 * len - 1;
                l1 = j, r1 = j + len - 1;
                ifn(pref_y[r][r1] - pref_y[r][l1 - 1] - pref_y[l - 1][r1] + pref_y[l - 1][l1 - 1] == sqr(len))ok = 0;

                l = i + len, r = i + 2 * len - 1;
                l1 = j + len, r1 = j + 2 * len - 1;
                ifn(pref_b[r][r1] - pref_b[r][l1 - 1] - pref_b[l - 1][r1] + pref_b[l - 1][l1 - 1] == sqr(len))ok = 0;
                if(ok)pref_good[len][i][j] = 1;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                pref_good[len][i][j] += pref_good[len][i - 1][j] + pref_good[len][i][j - 1] - pref_good[len][i - 1][j - 1];
            }
        }
    }

    while(q--){
        ll l, l1, r, r1;
        cin >> l >> l1 >> r >> r1;
        ll ans = 0;
        for(int len = 1; len <= 250; len++){
            if(l + 2 * len - 1 <= r && l1 + 2 * len - 1 <= r1){
                if(pref_good[len][r - 2 * len + 1][r1 - 2 * len + 1] - pref_good[len][l - 1][r1 - 2 * len + 1] - pref_good[len][r - 2 * len + 1][l1 - 1] + pref_good[len][l - 1][l1 - 1] > 0)
                    ans = len;
            }
        }
        cout << sqr(2 * ans) << "\n";
    }

    return 0;
}