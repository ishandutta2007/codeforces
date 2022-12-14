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
ll b[MAXN];
int main() {
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll n, k;
    cin >> n >> k;
    vector <ll> a(k);
    for(int i = 0; i < k; i++)cin >> a[i];
    for(int i = 0; i < k; i++)b[a[i]]++;
    for(int j = 10001; j > 0; j--){
        ll sc = 0;
        for(int i = 1; i < 101; i++)sc += b[i] / j;
        if(sc >= n)vout(j);
    }
    vout(0);
    return 0;
}