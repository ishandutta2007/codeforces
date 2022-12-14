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

vector <ll> v[100];

ll uk[65];
ll mn[100];

ll pref1[MAXN];
ll pref2[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    vector <ll> a(n);
    vector <ll> pref(n);
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        while(x){
            if(x % 2)a[i]++;
            x >>= 1;
        }

        pref[i] = a[i];
        if(i)pref[i] += pref[i - 1];
        if(i)pref1[i] += pref1[i - 1];
        if(i)pref2[i] += pref2[i - 1];
        if(pref[i] % 2 == 0)pref2[i]++;
        else pref1[i]++;
        v[a[i]].p_b(i);
    }
    for(int i = 1; i < 65; i++){
        reverse(all(v[i]));
    }

    ll ans = 0;
    ll sc = 0;
    for(int i = 0; i < n; i++){
        //cout << pref[i] << endl;
        for(int j = 1; j < 65; j++){
            while(uk[j] < n && pref[uk[j]] - sc < 2 * j)uk[j]++;
        }
        ll mnn = n;

        for(int j = 64; j > 0; j--){
            mn[j] = mnn;
            if(!v[j].empty())mnn = min(v[j].back(), mnn);
        }
        for(int j = 1; j < 65; j++)if(!v[j].empty() && uk[j] < n){
            ll pos = v[j].back();
            ll l = pos, r = mn[j];
            if(l < r && uk[j] < r){
                if(sc % 2 == 0){
                    ll res = pref2[r - 1];
                    if(max(l, uk[j]))res -= pref2[max(l, uk[j]) - 1];
                    ans += res;
                }else {
                    ll res = pref1[r - 1];
                    if(max(l, uk[j]))res -= pref1[max(l, uk[j]) - 1];
                    ans += res;
                }

            }
        }
        sc += a[i];
        v[a[i]].pop_back();
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}