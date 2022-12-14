#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 2123456;
const ll N = 2e5;
const ll inf = 1e18;
const ll buben = 338;
const ll mod = 1e9 + 7;
const ll step = 200003;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll f(ll x){
    return x * (x + 1) / 2;
}

ll a[301][301];
ll c[301], r[301];

void solve(){
    ll n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
        a[i][j] = 0;
    }

    ll d = k / n;

    ll pos = 1;

    for(int i = 1; i <= n; i++, pos++){
        if(pos > n){
            pos %= n;
            if(!pos)pos = n;
        }
        for(int j = pos; j <= pos + d - 1; j++){
            ll c = j;
            if(c >= n){
                c %= n;
                if(!c)c = n;
            }
            a[i][c] = 1;
        }
    }

    pos = 1;

    for(int i = 1; i <= k % n; i++, pos++){
        pos %= n;
        if(!pos)pos = n;
        ll c = pos + d;
        c %= n;
        if(!c)c = n;
        a[i][c] = 1;
    }


    fill(c, c + 301, 0);
    fill(r, r + 301, 0);

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
        r[i] += a[i][j];
        c[j] += a[i][j];
    }

    ll max_y, max_x, min_y, min_x;

    max_y = max_x = 0;
    min_y = min_x = n;

    for(int i = 1; i <= n; i++){
        max_y = max(max_y, r[i]);
        max_x = max(max_x, c[i]);
        min_y = min(min_y, r[i]);
        min_x = min(min_x, c[i]);
    }
    cout << sqr(max_y - min_y) + sqr(max_x - min_x) << "\n";

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)cout << a[i][j];
        cout << "\n";
    }

}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    cin >> t;

    while(t--)solve();



    return 0;
}