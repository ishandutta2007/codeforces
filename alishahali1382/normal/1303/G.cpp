#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 150010, LOG=20;

struct CHT{
    typedef pair < ll , ll > Line;
	set < pair < Line , ll > > S;
    set < pair < ll , Line > > I;
    ll INF = 4e18;
    inline void Add(Line X)
    {
        ll t = -INF;
        auto it = S.lower_bound({X, -INF});
        while ((int)S.size())
        {
            if (it == S.begin())
                {t = -INF; break;}
            it --; ll r = Intersection(it->first, X);
            if (r <= it->second)
                I.erase({it->second, it->first}), it = S.erase(it);
            else
                {t = r; break;}
        }
        it = S.lower_bound({X, -INF});
        while ((int)S.size())
        {
            if (it == S.end())
                break;
            ll r = Intersection(X, it->first);
            Line Y = it->first;
            I.erase({it->second, it->first});
            it = S.erase(it);
            if (r <= t)
            {
                r = -INF;
                if (it != S.begin())
                    it --, r = Intersection(it->first, Y);
                S.insert({Y, r}); I.insert({r, Y}); return ;
            }
            if (it != S.end() && it->second <= r)
                continue;
            S.insert({Y, r}); I.insert({r, Y}); break;
        }
        S.insert({X, t}); I.insert({t, X});
    }
    inline ll GetMax(ll X)
    {
        auto it = I.upper_bound({X, {INF, INF}}); it --;
        return (X * it->second.first + it->second.second);
    }
    inline ll Intersection(Line X, Line Y)
    {
        if (X.first == Y.first && X.second <= Y.second)
            return (-INF);
        if (X.first == Y.first)
            return (INF);
        return ((X.second - Y.second) / (Y.first - X.first)) + ((X.second - Y.second) % (Y.first - X.first) > 0);
    }
    inline void clear(){
    	I.clear();
    	S.clear();
	}
};

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
int sz[MAXN];
bool dead[MAXN];
vector<int> G[MAXN];
CHT cht;

int dfs1(int node, int par){
	sz[node]=1;
	for (int v:G[node]) if (v!=par && !dead[v]) sz[node]+=dfs1(v, node);
	return sz[node];
}

int Centroid(int node, int par, int n){
	for (int v:G[node]) if (!dead[v] && v!=par && 2*sz[v]>n) return Centroid(v, node, n);
	return node;
}

void dfs2(int node, int par, int h, ll val, ll sum){
	sum+=A[node];
	val+=A[node]*(h+1);
	ans=max(ans, cht.GetMax(sum) + val);
	for (int v:G[node]) if (v!=par && !dead[v]) dfs2(v, node, h+1, val, sum);
}

void dfs3(int node, int par, int h, ll val, ll sum){
	sum+=A[node];
	val+=sum;
	cht.Add({h, val});
	for (int v:G[node]) if (v!=par && !dead[v]) dfs3(v, node, h+1, val, sum);
}

void Decompose(int root){
	root=Centroid(root, root, dfs1(root, root));
	
	dead[root]=1;
	for (int shit=0; shit<2; shit++){
		cht.clear();
		cht.Add({0, 0});
		for (int v:G[root]) if (!dead[v]){
			dfs2(v, root, 1, A[root], A[root]);
			dfs3(v, root, 1, 0, 0);
		}
		ans=max(ans, cht.GetMax(A[root])+A[root]);
		reverse(all(G[root]));
	}
	for (int v:G[root]) if (!dead[v]) Decompose(v);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++) cin>>A[i];
	
	Decompose(1);
	cout<<ans<<'\n';
	
	return 0;
}