#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll M = 5032110;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll last[5 * MAXN];

vector <ll> v[MAXN];

ll kek[M + 2][8];

ll poz[N][15];

ll sp[N][15][18];

ll st[N + 5];

ll get(ll l, ll r, ll x){
    return min(sp[l][x][st[r - l + 1]], sp[r - pw(st[r - l + 1]) + 1][x][st[r - l + 1]]);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    for(int i = 2; i <= M; i++)if(!last[i]){
        for(int j = i; j <= M; j += i)last[j] = i;
    }

    vector <ll> a(n + 1), b(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= M; i++)
        for(int j = 0; j < 8; j++)kek[i][j] = 1e18;

    for(int i = 1; i <= n; i++){
        ll x = a[i];
        b[i] = 1;
        while(x != 1){
            ll t = last[x], fc = 0;
            while(x % t == 0){
                fc ^= 1;
                x /= t;
            }
            if(fc){
                b[i] *= t;
                v[i].p_b(t);
            }
        }
    }

    ll pr = 1;

    for(int i = n; i > 0; i--){

        for(int j = 0; j < 15; j++)poz[i][j] = 1e18;

        for(int j = 0; j < pw(v[i].size()); j++){
            pr = 1;
            for(int i1 = 0; i1 < v[i].size(); i1++)if((j & pw(i1)))pr *= v[i][i1];
            for(int i1 = 0; i1 < 8; i1++)
                poz[i][i1 + v[i].size()- __builtin_popcount(j)] = min(poz[i][i1 + v[i].size() - __builtin_popcount(j)], kek[pr][i1]);

            kek[pr][ll(v[i].size()) - __builtin_popcount(j)] = i;
        }

        for(int j = 0; j < 15; j++)sp[i][j][0] = poz[i][j];

    }


    for(int step = 1; step < 18; step++)
        for(int i = 1; i <= n; i++)
        for(int j = 0; j < 15; j++)sp[i][j][step] = min(sp[i][j][step - 1], sp[min(n, ll(i + pw(step - 1)))][j][step - 1]);

    ll k = 0;

    for(int i = 1; i <= N; i++){
        while(pw(k + 1) < i)k++;
        st[i] = k;
    }

    while(q--){
        ll l, r;
        cin >> l >> r;
        ll ans = 1e18;
        for(int i = 0; i < 15; i++)if(get(l, r, i) <= r){
            ans = i;
            break;
        }
        cout << ans << "\n";
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}