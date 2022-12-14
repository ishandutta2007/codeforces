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
ll a[MAXN], b[MAXN], c[MAXN], last;
int main(){
    ll n, m;
    cin >> n >> m;
    ll sc = 0;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++){
        if(a[i] < m)b[i] = -1; else if(a[i] > m)b[i] = 1;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        c[i] = sc;
        sc += b[i];
        if(!b[i]){
            for(int j = last + 1; j <= i; j++)mp[c[j]]++;
            last = i;
        }
        //cout << c[i] << endl;
        ans += mp[sc];
        ans += mp[sc - 1];
    }
    vout(ans);
    return 0;
}