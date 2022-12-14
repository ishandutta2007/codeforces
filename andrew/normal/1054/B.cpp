#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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

ll b[MAXN], c[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, ans = 1e18;
    cin >> n;
    for(int i = 0; i < MAXN; i++)b[i] = 1e18;
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < n){
            b[a[i]] = min(b[a[i]], ll(i));
        }
    }
    ll mx = -1e18;
    for(int i = 0; i <= n; i++){
        mx = max(mx, b[i]);
        c[i] = mx;
    }
    for(int i = 1; i <= n; i++){
        if(a[i] >= n)vout(i);
        if(c[a[i]] > i)vout(i);
    }
    vout(-1);
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}