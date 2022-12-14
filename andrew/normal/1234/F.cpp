#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 3e18;
const ll mod = 998244353;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int dp[MAXN][21], mxL[MAXN];

bool fl[MAXN][21], f1[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    string s;
    cin >> s;

    ll n = s.size(), ans = 0;

    for(int i = 0; i < n; i++){
        ll musk = 0, h;
        for(int j = i; j < n; j++){
            h = s[j] - 'a';
            if((musk & pw(h)))break;
            ans = max(ans, ll(j - i + 1));
            musk |= pw(h);
            if(!f1[musk]){
                mxL[musk] = i;
                f1[musk] = 1;
            }else{
                mxL[musk] = max(mxL[musk], i);
            }
        }
    }


    f1[0] = 1;

    for(int i = 0; i < pw(20); i++)if(f1[i]){
        dp[i][__builtin_popcount(i)] = mxL[i];
    }

    for(int i = 0; i < pw(20); i++){
        for(int j = 0; j < 20; j++)if((i & pw(j))){
            for(int i1 = 1; i1 <= __builtin_popcount(i); i1++)dp[i][i1] = max(dp[i][i1], dp[i ^ pw(j)][i1]);
        }
    }

    for(int i = 0; i < n; i++){
        ll musk = 0, h;
        for(int j = i; j < n; j++){
            h = s[j] - 'a';
            if((musk & pw(h)))break;
            musk |= pw(h);
            ll top = (pw(20) - 1) ^ musk;
            for(int len = 1; len <= __builtin_popcount(top); len++)if(dp[top][len] > j){
                ans = max(ans, ll(j - i + 1) + len);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}