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
const int MAXN = 100010, SGM=26;

int n, m, k, u, v, x, y, t, a, b, ans;
int C[MAXN][SGM], F[MAXN], ts;
int pos[MAXN], up[MAXN], K[MAXN];
vector<int> vec[MAXN];
string M[MAXN], S;

int AddTrie(string &s){
	int v=0;
	for (char ch:s){
		if (!C[v][ch-'a']) C[v][ch-'a']=++ts;
		v=C[v][ch-'a'];
	}
	return v;
}

void BuildAho(){
	queue<int> Q;
	for (int i=0; i<SGM; i++) if (C[0][i]) Q.push(C[0][i]);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		if (!up[v]) up[v]=up[F[v]];
		for (int i=0; i<SGM; i++){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				F[C[v][i]]=C[F[v]][i];
				Q.push(C[v][i]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S>>n;
	for (int i=1; i<=n; i++) cin>>K[i]>>M[i], up[pos[i]=AddTrie(M[i])]=i;
	BuildAho();
	
	int v=0;
	for (int i=0; i<S.size(); i++){
		int ch=S[i]-'a';
		v=C[v][ch];
		//debug2(i, v)
		for (int u=pos[up[v]]; u; u=pos[up[F[u]]]) vec[up[u]].pb(i);
	}
	
	for (int i=1; i<=n; i++){
		k=K[i];
		if (vec[i].size()<k){
			cout<<"-1\n";
			continue ;
		}
		ans=inf;
		for (int j=k-1; j<vec[i].size(); j++) ans=min(ans, vec[i][j]-vec[i][j-k+1]);
		cout<<ans+M[i].size()<<'\n';
	}
	
	return 0;
}