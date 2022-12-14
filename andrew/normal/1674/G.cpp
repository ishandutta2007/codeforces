#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 1123456;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll in[MAXN], out[MAXN], n;
vector <ll> v[MAXN];
ll dp[MAXN];
bool used[MAXN];
vector<ll> ans;
 
void dfs(int x) {
    if (used[x]) return;
	used[x] = true;
	for (auto to : v[x]) {
		dfs(to);
	}
	ans.push_back(x);
}
 
void topological_sort() {
	for (int i = 0; i < n; i++) dfs(i);
    reverse(all(ans));	
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        //  cin >> t;
    #endif   
     
    
    int m;
    cin >> n >> m;
    while (m--) {
        ll a, b; 
        cin >> a >> b; 
        v[a].p_b(b);
        out[a]++;
        in[b]++;
    }

    ll res = 0;

    topological_sort();

    for (auto idx : ans) {
        dp[idx] = max(dp[idx], 1LL);
        if (out[idx] > 1) {
            for (auto to : v[idx]) {
                if (in[to] > 1) {
                    dp[to] = max(dp[to], dp[idx] + 1);
                }
            }
        }        
        res = max(res, dp[idx]);
    }

    cout << res << "\n";

    return 0;
}