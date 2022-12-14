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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
T sqr(T x){
    return x * x;
}

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

const ll MOD = 1e9 + 7;

ll mul(ll a, ll b){
    return (a * b) % MOD;
}

ll sum(ll a, ll b){
    return (a + b) % MOD;
}

ll fact[MAXN];

ll f(ll x){
    return fact[x];
}

void Evkl(ll a, ll b, ll &x, ll &y){
    if(!a){
        x = 0, y = 1;
        return;
    }
    ll x1, y1;
    Evkl(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;
}

ll inv(ll a){
    ll x, y;
    Evkl(a, MOD, x, y);
    x = (x + MOD) % MOD;
    return x;
}

ll divMOD(ll a, ll b){
    return mul(a, inv(b));
}

ll C(ll n, ll k){
    return divMOD(f(n), mul(f(k), f(n - k)));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    cin >> s;
    ll n = s.size();

    fact[0] = 1;

    for(int i = 1; i <= 300000; i++)fact[i] = mul(fact[i - 1], ll(i));



    ll ans = 0;

    ll kol = 0;

    for(int i = n - 1; i >= 0; i--){
        if(s[i] == ')')kol++;
    }

    ll kol1 = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == ')'){
            kol--;
            continue;
        }
        kol1++;
        if(!kol)continue;
        ans = sum(ans, C(kol + kol1 - 1, kol1));
    }
    printf("%lld\n", ans);

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}