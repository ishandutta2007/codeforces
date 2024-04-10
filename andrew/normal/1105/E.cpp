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
#define sset ordered_set

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

unordered_map <string, ll> mp;

vector <ll> v[MAXN];

bool f[100011][41];

bitset <100011> c[41];

bool fl[41][41];

bool kek[MAXN];

ll dp[MAXN], mb[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;

    cin >> n >> m;

    if(m == 1)vout(1);

    vector <ll> pos;

    ll last = 0;

    for(int i = 1; i <= n; i++){
        ll t;
        cin >> t;
        if(t == 1){
            last = i;
        }else{
            string s;
            cin >> s;
            if(!mp[s])mp[s] = mp.size();
            ll x = mp[s] - 1;
            if(v[x].empty() || v[x].back() != last)v[x].p_b(last);

            f[last][x] = 1;
            c[x][last] = 1;

        }
    }

    ll k = m / 2;

    for(int i = 0; i < m; i++){
        mb[i] = (1ll << m) - 1;
        for(int j = 0; j < m; j++)if(i != j){
            if((c[i] & c[j]).any()){
                fl[i][j] = 1;
                mb[i] ^= 1ll << j;
            }
        }

        if(i < k){
            for(int j = 0; j < k; j++)if(i != j && fl[i][j]){
                kek[(1ll << j) | (1ll << i)] = 1;
            }
        }

    }


    ll musk = 1ll << k;

    for(int i = 0; i < musk; i++)if(kek[i]){
        for(int j = 0; j < k; j++)kek[(1ll << j) | i] = 1;
    }

    ll ans = 0;

    for(int i = 0; i < musk; i++){

        if(!kek[i]){
            dp[i] = max(ll(__builtin_popcount(i)), dp[i]);
            ans = max(ans, dp[i]);
        }

        for(int j = 0; j < k; j++)dp[i | (1ll << j)] = max(dp[i | (1ll << j)], dp[i]);
    }

    ll mk = (1ll << k) - 1;


    ll kol = m - k;
    ll msk = 1ll << kol;

    for(int i = 0; i < msk; i++)kek[i] = 0;

    for(int i = k; i < m; i++)
        for(int j = k; j < m; j++)if(i != j){
            if(fl[i][j]){
                kek[(1ll << (i - k)) | (1ll << (j - k))] = 1;
            }
        }

    for(int i = 0; i < msk; i++)if(kek[i]){
        for(int j = 0; j < kol; j++)kek[(1ll << j) | i] = 1;
    }


    for(int i = 0; i < msk; i++)if(!kek[i]){
        ll sc = __builtin_popcount(i);
        ll mbb = mk;

        for(int j = 0; j < kol; j++)if(((1ll << j) & i)){
            mbb &= mb[j + k];
        }
        //cout << mk << "\n";
        sc += dp[mbb];
        ans = max(ans, sc);
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}