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
   ll n;
   cin >> n;
   vector <ll> a(n), b;
   for(int i = 0; i < n; i++)cin >> a[i];
   for(int i = 1; i < n; i++)if(a[i] == 1)b.p_b(a[i - 1]);
   b.p_b(a[n - 1]);
   cout << b.size() << endl;
   for(auto i : b)cout << i << " ";
    return 0;
}