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
   ll l;
   string a, b;
   cin >> a >> b;
   l = 0;
   if(a.size() > b.size())swap(a, b);
   reverse(all(a));
   reverse(all(b));
   while(l < a.size() && a[l] == b[l])l++;
   cout << a.size() + b.size() - 2 * l << endl;
    return 0;
}