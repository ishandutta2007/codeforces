#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector < pair <pll, ll> > v[MAXN], v1[MAXN];
ll p[1101][26];

char a[1101][1101];

ll f[1101][1101], val[1101][1101];
ll kol[26], Skol;
ll pref[1101][1101][26];

struct rectangle{
    ll l, r, l1, r1;
    char ch;
};

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)cin >> a[i][j];

    vector <rectangle> b(k);

    ll ans = 1e18;

    for(int i = 0; i < k; i++){
        cin >> b[i].l >> b[i].l1 >> b[i].r >> b[i].r1 >> b[i].ch;
        v[b[i].l].p_b({{b[i].l1, b[i].r1}, b[i].ch - 'a'});
        v1[b[i].r + 1].p_b({{b[i].l1, b[i].r1}, b[i].ch - 'a'});
    }

    for(int i = 1; i <= n; i++){

        for(auto j : v1[i]){
            p[j.fi.fi][j.se]--;
            p[j.fi.se + 1][j.se]++;
        }

        for(auto j : v[i]){
            p[j.fi.fi][j.se]++;
            p[j.fi.se + 1][j.se]--;
        }

        Skol = 0;
        for(int j = 0; j < 26; j++)kol[j] = 0;

        for(int pos = 1; pos <= m; pos++){
            for(int j = 0; j < 26; j++){
                Skol += p[pos][j];
                kol[j] += p[pos][j];
                val[i][pos] += abs(j + 'a' - a[i][pos]) * kol[j];
            }

            for(int j = 0; j < 26; j++){
                ll sc = kol[j];
                if(j == a[i][pos] - 'a')sc += k - Skol;
                pref[i][pos][j] = sc + pref[i - 1][pos][j] + pref[i][pos - 1][j] - pref[i - 1][pos - 1][j];
            }

            f[i][pos] = val[i][pos] + f[i - 1][pos] + f[i][pos - 1] - f[i - 1][pos - 1];
        }

    }

    for(int i = 0; i < k; i++){
        ll sc = f[n][m];
        ll l = b[i].l, r = b[i].r, l1 = b[i].l1, r1 = b[i].r1;
        ll cnt = f[r][r1] - f[r][l1 - 1] - f[l - 1][r1] + f[l - 1][l1 - 1];
        sc -= cnt;
        for(int j = 0; j < 26; j++){
            ll cnt = pref[r][r1][j] - pref[r][l1 - 1][j] - pref[l - 1][r1][j] + pref[l - 1][l1 - 1][j];
            sc += cnt * abs(j + 'a' - b[i].ch);
        }
        ans = min(ans, sc);
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}