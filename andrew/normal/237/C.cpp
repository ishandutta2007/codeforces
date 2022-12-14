#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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
ll l, r, k;
ll pref[2 * MAXN];

ll get(ll l, ll r){
    return pref[r] - pref[l - 1];
}

bool check(ll x){
    for(int i = l; i <= r - x + 1; i++)if(get(i, i + x - 1) < k)return 0;
    return 1;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> l >> r >> k;
    vector <ll> prime(1e6 + 1);
    ll N = 1e6;
    for(int i = 2; i <= N; i++)if(!prime[i]){
        if(ll(i) * ll(i) <= N){
            for(int j = i * i; j <= N; j += i)prime[j] = 1;
        }
    }
    for(int i = 2; i <= N; i++)pref[i] = pref[i - 1] + 1 - prime[i];
    if(get(l, r) < k)vout(-1);
    int l1 = 1, r1 = r - l + 1;
    while(l1 < r1){
        int c = (l1 + r1) >> 1;
        if(check(c))r1 = c; else l1 = c + 1;
    }
    cout << l1 << "\n";
    return 0;
}