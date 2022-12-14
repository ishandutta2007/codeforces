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
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n), ans(m);
    vector <pll> b(m);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < m; i++)cin >> b[i].fi;
    for(int i = 0; i < m; i++)b[i].se = i;
    sort(all(a));
    ll uk = 0;
    sort(all(b));
    for(int i = 0; i < m; i++){
        while(uk < a.size() && a[uk] <= b[i].fi)uk++;
        ans[b[i].se] = uk;
    }
    for(int i = 0; i < m; i++)cout << ans[i] << " ";
    return 0;
}