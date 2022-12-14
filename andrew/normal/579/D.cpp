#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m, k, x;
    cin >> n >> k >> x;
    vector <ll> a(n + 1), b(n + 10), c(n + 10);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = b[i - 1] | a[i];
    }
    for(int i = n; i > 0; i--)c[i] = c[i + 1] | a[i];
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll val = a[i];
        for(int j = 0; j < k; j++)val *= x;
        ans = max(ans, val | b[i - 1] | c[i + 1]);
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}