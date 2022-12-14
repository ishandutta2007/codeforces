#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T> T nxt(){T a; cin >> a; return a;}

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
    ll N = 1e5 + 1;
    vector <bool> f(N);
    ll n;
    cin >> n;
    f[0] = 1;
    while(n--){
        ll x;
        cin >> x;
        for(int i = x; i <= N; i++)f[i] = f[i - x] | f[i];
    }
    for(int i = 1; i <= N; i++)if(!f[i])return cout << i << "\n", 0;
    return cout << -1 << "\n", 0;
}