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
    ll n;
    cin >> n;
    vector <ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    vector <ll> b(n);
    for(int i = 0; i < n; i++){
        a[i] -= i;
        if(a[i] < 1)vout(i + 1);
        b[i] = a[i] / n;
        if(a[i] % n)b[i]++;
    }
    ll mn = 1e18;
    for(int i = 0; i < n; i++)mn = min(mn, b[i]);
    for(int i = 0; i < n; i++)if(b[i] == mn)vout(i + 1);
    return 0;
}