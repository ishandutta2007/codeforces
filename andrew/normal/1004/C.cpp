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

map <ll, ll> mp;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    set <ll> s1;
    set <ll> s;
    vector <ll> a(n + 1);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
        s.insert(a[i]);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        mp[a[i]]--;
        if(!mp[a[i]])s.erase(a[i]);
        if(s1.find(a[i]) == s1.end()) ans += s.size();
        s1.insert(a[i]);
    }
    cout << ans << endl;
    return 0;
}