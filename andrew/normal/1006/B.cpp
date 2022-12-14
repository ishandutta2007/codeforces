#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

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

ll last = 0;
set <pll> s;
set <ll> a;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll last = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        s.insert({x, i});
        a.insert(i);
        ans += x;
        if(s.size() > k){
            a.erase((s.begin())->se);
            ans -= s.begin() -> fi;
            s.erase(s.begin());
        }
    }
    k--;
    cout << ans << "\n";
    for(auto i : a){
        if(!k)break;
        k--;
        cout << i - last << " ";
        last = i;
    }
    cout << n - last << "\n";
}