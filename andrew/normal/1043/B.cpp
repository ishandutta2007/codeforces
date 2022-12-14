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
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    vector <ll> ans;
    for(int i = 1; i <= n; i++){
        vector <ll> b;
        for(int j = 1; j <= i; j++)b.p_b(a[j] - a[j - 1]);
        bool fl = 0;
        for(int j = 1; j <= n; j++)if(a[j] != a[j - 1] + b[(j - 1) % i])fl = 1;
        if(!fl)ans.p_b(i);
    }
    cout << ans.size() << "\n";
    for(auto i : ans)cout << i << " ";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}