#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define next ku
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
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    vector <ll> a;
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
                         ll x;
                         cin >> x;
                         a.p_b(x);
    }
    while(a.size() && a.back() <= k)a.pop_back();
    reverse(all(a));
    while(a.size() && a.back() <= k)a.pop_back();
    cout << n - a.size() << endl;
}