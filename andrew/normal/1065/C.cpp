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
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    ll x = a.back();
    while(!a.empty() && a.back() == x)a.pop_back();
    if(a.empty())vout(0);
    ll sum = 0;
    ll kol = 0, ans = 0;
    reverse(all(a));
    for(int i = 200000; i > x; i--){
        ll kol1 = 0, sum1 = 0;
        sum += kol;
        while(!a.empty() && a.back() >= i){
            sum1 += a.back() - i;
            kol1++;
            a.pop_back();
        }
        sum += sum1;
        kol += kol1;
        //cout << sum << " " << kol << " " << i << "\n";
        if(sum + kol > k){
            sum = 0;
            ans++;
        }
    }
    vout(ans + 1);
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}