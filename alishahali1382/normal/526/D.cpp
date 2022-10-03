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
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int f[MAXN];
int stt[MAXN], fnt[MAXN], timer=1;
int ans[MAXN];
vector<int> G[MAXN];
string S;

void dfs(int node){
	stt[node]=timer++;
	for (int v:G[node]) dfs(v);
	fnt[node]=timer;
}

bool is_par(int u, int v){
	return stt[u]<=stt[v] && fnt[v]<=fnt[u];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>S;
	int curr=0;
	for (int i=1; i<n; i++){
		while (curr && S[curr]!=S[i]) curr=f[curr];
		f[i+1]=curr+=(S[curr]==S[i]);
	}
	
	for (int i=1; i<=n; i++) G[f[i]].pb(i);
	dfs(0);
	
	for (int len=1; len*k<=n; len++) if (is_par(len*(k-1), len*k)){
		int dwn=0, up=min(len, n-len*k)+1;
		while (up-dwn>1){
			int mid=(dwn+up)>>1;
			if (is_par(mid, mid+len*k)) dwn=mid;
			else up=mid;
		}
		ans[len*k]++;
		ans[len*k+up]--;
	}
	
	for (int i=1; i<=n; i++) cout<<((ans[i]+=ans[i-1])>0);
	
	return 0;
}