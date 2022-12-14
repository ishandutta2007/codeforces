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
map <ll, ll> mp;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector <ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(all(a));
    ll lst = 0, k = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 2 * lst){
            ans = max(ans, k);
            k = 0;
        }
        lst = a[i];
        k++;
    }
    ans = max(ans, k);
    cout << ans << endl;
    return 0;
}