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

ll f[MAXN], res[MAXN], ans, kol[MAXN];
bool fl[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    if(n == 1)vout(1);
    for(int i = 2; i <= n; i++)if(!f[i]){
        f[i] = i;
        if(ll(i) * ll(i) <= ll(n))for(int j = i * i; j <= n; j += i)if(!f[j])f[j] = i;
    }
    //cout << 1 << endl;
    ans = 1;
    ll l = 1, ost = n;
    while(l <= n){
        for(int i = 1; i <= n; i++){
            kol[i] = 0;
            if(!fl[i]){
                ll x = i / ans;
                while(x != 1){
                    ll p = f[x];
                    while(x % p == 0)x /= p;
                    kol[p]++;
                }
        }
        }
        ll mx = 0, mxj = 0;
        for(int i = 2; i <= n; i++)if(kol[i] >= mx){
            mx = kol[i];
            mxj = i;
        }
        ll keks = ost - mx;
        ost -= keks;
        while(keks){
            res[l] = ans;
            keks--;
            l++;
        }
        ans *= mxj;
        for(int i = 1; i <= n; i++)if(i % ans != 0)fl[i] = 1;
        ll kek = 0;
        for(int i = 2; i <= n; i++)if(!fl[i]){
            kek = __gcd(i / ans, kek);
        }
        //cout << ans << " " << kek << endl;
        //cout << ost << endl;
        ans *= kek;
    }
    for(int i = 1; i <= n; i++)cout << res[i] << " ";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}