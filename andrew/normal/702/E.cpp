#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

const ll N = 1e5 + 1;

ll pr[N][36], s[N][36], m[N][36];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, k;
    cin >> n >> k;

    vector <ll> f(n + 1), w(n + 1);

    for(int i = 1; i <= n; i++)cin >> f[i];
    for(int i = 1; i <= n; i++)cin >> w[i];

    for(int i = 1; i <= n; i++){
        pr[i][0] = f[i] + 1;
        s[i][0] = w[i];
        m[i][0] = w[i];
    }

    for(int j = 1; j < 36; j++)
    for(int i = 1; i <= n; i++){
        ll x = pr[pr[i][j - 1]][j - 1];
        pr[i][j] = x;
        s[i][j] = s[i][j - 1] + s[pr[i][j - 1]][j - 1];
        m[i][j] = min(m[i][j - 1], m[pr[i][j - 1]][j - 1]);
    }

    for(int i = 1; i <= n; i++){
        ll sum = 0, x = i, mn = 1e18;
        for(int j = 35; j >= 0; j--)if(((1ll << j) & k)){
            mn = min(mn, m[x][j]);
            sum += s[x][j];
            x = pr[x][j];
        }
        cout << sum << " " << mn << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}