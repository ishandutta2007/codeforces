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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    vector <ll> a(n * 2);
    for(int i = 0; i < n * 2; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]] >= n)vout(0);
    }
    sort(all(a));
    ll ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
    for(int i = 1; i < n; i++)ans = min(ans, (a[n * 2 - 1] - a[0]) * (a[i + n - 1] - a[i]));
    vout(ans);
    return 0;
}