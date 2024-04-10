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



ll dp[1000001][2][2];
ll d[1000001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, k;
    cin >> n >> k;
    string l, r;
    cin >> l >> r;

    l = "#" + l;
    r = "#" + r;

    dp[0][0][0] = 1;

    for(int i = 1; i <= n; i++){
        char lc = l[i], rc = r[i];

        for(int j = 0; j < 2; j++)
            for(int i1 = 0; i1 < 2; i1++)
        for(char mb = 'a'; mb <= 'b'; mb++){
            char l1 = lc, r1 = rc;
            if(j)l1 = 'a' - 1;
            if(i1)r1 = 'c';
            if(l1 <= mb && mb <= r1){
                bool fl = 0, fr = 0;
                if(l1 < mb)fl = 1;
                if(mb < r1)fr = 1;
                dp[i][fl][fr] += dp[i - 1][j][i1];
                dp[i][fl][fr] = min(dp[i][fl][fr], k);
            }
        }

    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++)
            for(int i1 = 0; i1 < 2; i1++)d[i] += dp[i][j][i1];
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++)ans += min(d[i], k);

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}