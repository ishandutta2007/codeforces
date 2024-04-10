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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 5010, K=16;

ll n, m, k, u, v, x, y, t, a, b, sum;
ll A[K][MAXN];
ll B[K];
pii way[1<<K];
bool good[1<<K];
bool mark[K];
bool dp[1<<K];
int par[1<<K];
ll out[MAXN], in[MAXN];
ll ans1[K], ans2[K];
map<int, int> id;

bool go(int v, ll s, int start, ll startout){
	//cerr<<"go "<<v<<' '<<s<<endl;
	if (!id.count(sum-s)) return 0;
	int nxt=id[sum-s];
	in[v]=sum-s;
	out[v]=B[v]-s;
	mark[v]=1;
	if (nxt==start) return in[v]==startout;
	if (mark[nxt]) return 0;
	return go(nxt, B[nxt]-in[v], start, startout);
}

int get_mark(){
	int res=0;
	for (int i=0; i<n; i++) if (mark[i]) res|=(1<<i);
	return res;
}

void fuck(int mask){
	if (!mask) return ;
	int sub=par[mask];
	int v=way[sub].first, w=way[sub].second;
	memset(mark, 0, sizeof(mark));
	go(v, B[v]-w, v, w);
	fuck(mask^sub);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i][0];
		for (int j=1; j<=A[i][0]; j++){
			cin>>A[i][j];
			id[A[i][j]]=i;
			B[i]+=A[i][j];
		}
		sum+=B[i];
	}
	if (sum%n) kill("No")
	sum/=n;
	/*
	debug(sum)
	debug(B[3])
	debug(go(0, 5, 0, 7))
	*/
	for (int i=0; i<n; i++){
		for (int j=1; j<=A[i][0]; j++){
			memset(mark, 0, sizeof(mark));
			if (go(i, B[i]-A[i][j], i, A[i][j])){
				int mask=get_mark();
				good[mask]=1;
				way[mask]={i, A[i][j]};
				//debug2(i, A[i][j])
			}
		}
	}
	dp[0]=1;
	for (int mask=1; mask<(1<<n); mask++){
		for (int sub=mask; sub && !dp[mask]; sub=(sub-1)&mask) if (good[sub] && dp[mask^sub]){
			dp[mask]=1;
			par[mask]=sub;
		}
	}
	if (!dp[(1<<n)-1]) kill("No")
	cout<<"Yes\n";
	fuck((1<<n)-1);
	for (int i=0; i<n; i++){
		ans1[id[in[i]]]=i;
		ans2[id[in[i]]]=in[i];
	}
	for (int i=0; i<n; i++) cout<<ans2[i]<<' '<<ans1[i]+1<<'\n';
	
	return 0;
}