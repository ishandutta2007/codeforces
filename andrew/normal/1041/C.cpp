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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, m, d;
    cin >> n >> m >> d;
    vector <ll> ans(n);
    set <pll> s;
    ll time = 1, day = 1;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        s.insert({x, i});
    }
    set <pll> :: iterator it;
    while(!s.empty()){
        pll kek = m_p(time, -1e18);
        it = s.lower_bound(kek);
        if(it == s.end()){
            time = 1;
            day++;
            kek = m_p(time, -1e18);
            it = s.lower_bound(kek);
        }
        pll xe = *it;
        s.erase(it);
        ans[xe.se - 1] = day;
        time = xe.fi + d + 1;
    }
    cout << day << endl;
    for(auto i : ans)cout << i << " ";
    return 0;
}