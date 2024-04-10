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
    map <ll,ll> mp;
    ll last = 0;
    vector <ll> a(40);
    for(int n = 1; n <= 13; n++){
        ll ans = 0;
        mp.clear();
        for(ll a = 0; a <= n; a++)
            for(ll b = 0; b <= n; b++)if(a + b <= n)
                for(ll c = 0; c <= n; c++)if(a + b + c <= n)
                    for(ll d = 0; d <= n; d++)if(a + b + c + d == n && !mp[a + b * 5 + c * 10 + d * 50]){
                        ans++;
                        mp[a + b * 5 + c * 10 + d * 50] = 1;
                    }
                    a[n] = ans;
    }
    cin >> n;
    if(n <= 13)vout(a[n]);
    vout(a[13] + 49 * (n - 13));
    return 0;
}