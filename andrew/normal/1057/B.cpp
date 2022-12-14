#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
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

ll pref[MAXN];
ll get(ll l, ll r){
    return pref[r] - pref[l - 1];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    ll N = n + 1;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        pref[i] = x;
    }
    for(int i = 1; i <= N; i++)pref[i] += pref[i - 1];

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            ll time = j - i + 1;
            if(time * 100 < get(i, j))ans = max(ans, time);
        }
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}