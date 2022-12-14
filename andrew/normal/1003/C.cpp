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
    long double sc, ans, x;
    ans = -1e9;
    ll n, k;
    cin >> n >> k;
    vector <long double> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++){
        sc = 0;
        for(int j = i; j < n; j++){
            sc += a[j];
            if(j - i + 1 >= k)ans = max(ans, sc / (j - i + 1));
        }
    }
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}