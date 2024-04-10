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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    vector <ll> a(n);
    ll mn = 0;
    for(int i = 0; i < n; i++)a[i] = i + 1;
    ll k = 0, mxj = 1e18;
    for(int i = 1; i <= n; i++)if(n / i + i + (n % i != 0) < mxj){
        mxj = n / i + i + (n % i != 0);
        k = i;
    }
    ll bgn = 0;
    for(int i = 0; i < k; i++){
        reverse(a.begin() + bgn, a.begin() + bgn + n / k);
        bgn += n / k;
    }
    if(n % k)reverse(a.begin() + bgn, a.end());
    for(int i = 0; i < n; i++)cout << a[i] << " ";
    return 0;
}