#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector <ll> a(n + 2);

    for(int i = 1; i <= n; i++)cin >> a[i];
    ll ans = 0;
    a[n + 1] = 1001;
    for(int i = 1; i <= n; i++)if(a[i - 1] + 1 == a[i]){
        ll kol = 0;
        for(int j = i; j <= n; j++)if(a[j] + 1 != a[j + 1])break; else kol++;
        ans = max(ans, kol);
    }
    cout << min(n - 1, ans) << "\n";
    return 0;
}