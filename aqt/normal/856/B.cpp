#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 1000005

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

const ld PI = (ld)4*atanl(1);

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int T,N,dp[MAXN][2],lst[MAXN],pre[MAXN*2],to[MAXN*2],cnt;
bool vis[MAXN];
pll hsh[MAXN],power[MAXN];
vector<pll> hashes;
gp_hash_table<ll,pll> bad;

inline void add_edge(int a, int b){
    pre[++cnt] = lst[a];
    lst[a] = cnt, to[cnt] = b;
}

inline int gidx(pll h){
    auto it = lower_bound(all(hashes),h);
    if(it == hashes.end()) return -1;
    if(*it != h) return -1;
    return (int)(it-hashes.begin());
}

inline ll conv(pll a){
    return a.first<<31|a.second;
}

void solve(int node, int prev){
    dp[node][1] = 1, dp[node][0] = 0;
    vis[node] = true;
    for(int i=lst[node];i;i=pre[i]){
        int check = to[i];
        if(check == prev) continue;
        solve(check,node);
        dp[node][0]+=max(dp[check][0],dp[check][1]);
        dp[node][1]+=dp[check][0];
    }
}

int main(){
    fastio; cin >> T;
    power[0] = mp(1,1);
    for(int i=1; i<=1e6; i++){
        power[i].first = power[i-1].first*131%MOD2;
        power[i].second = power[i-1].second*31%MOD;
    }
    while(T--){
        hashes.clear();
        bad.clear();
        cnt = 0;
        cin >> N;
        for(int i=1; i<=N; i++){
            string s; cin >> s;
            for(int k=1; k<=s.size(); k++){
                hsh[k].first = (hsh[k-1].first*131+s[k-1])%MOD2;
                hsh[k].second = (hsh[k-1].second*31+s[k-1])%MOD;
                hashes.pb(hsh[k]);
                if(k > 1){
                    ll sub = (hsh[k].first-(s[0]*power[k-1].first)%MOD2+MOD2)%MOD2;
                    ll sub2 = (hsh[k].second-(s[0]*power[k-1].second)%MOD+MOD)%MOD;
                    bad[conv(hsh[k])] = mp(sub,sub2);
                }
            }
        }
        sort(all(hashes));
        complete_unique(hashes);
        int cnt = (int)hashes.size();
        for(int i=0; i<cnt; i++) lst[i] = 0, vis[i] = false;
        for(int i=0; i<hashes.size(); i++){
            if(bad.find(conv(hashes[i])) == bad.end()) continue;
            pll c2 = bad[conv(hashes[i])];
            int idx = gidx(c2);
            if(idx == -1) continue;
            add_edge(i,idx);
            add_edge(idx,i);
        }
        int res = 0;
        for(int i=0; i<cnt; i++){
            if(vis[i]) continue;
            solve(i,-1);
            res+=max(dp[i][0],dp[i][1]);
        }
        cout << res << endl;
    }
}