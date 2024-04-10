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
const int MAXN = 200010, SGM=26;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll G[MAXN];
string S[MAXN], T;
int F[MAXN];
int C[MAXN][SGM+1], ts;

void Add(string &s){
	int node=0;
	for (char ch:s){
		if (!C[node][ch-'a']) C[node][ch-'a']=++ts;
		node=C[node][ch-'a'];
	}
	C[node][SGM]++;
}

void BuildAho(){
	ts=0;
	memset(C, 0, sizeof(C));
	memset(F, 0, sizeof(F));
	for (int i=1; i<=n; i++) Add(S[i]);
		
	queue<int> Q;
	for (int i=0; i<SGM; i++) if (C[0][i]) Q.push(C[0][i]);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		C[v][SGM]+=C[F[v]][SGM];
		for (int i=0; i<SGM; i++){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				Q.push(C[v][i]);
				F[C[v][i]]=C[F[v]][i];
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>T>>n;
	m=T.size();
	T="."+T;
	for (int i=1; i<=n; i++) cin>>S[i];
	BuildAho();
	int v=0;
	for (int i=1; i<=m; i++) G[i]=C[v=C[v][T[i]-'a']][SGM];
	for (int i=1; i<=n; i++) reverse(all(S[i]));
	BuildAho();
	v=0;
	for (int i=m; i; i--){
		ans+=G[i]*C[v][SGM];
		v=C[v][T[i]-'a'];
	}
	cout<<ans<<'\n';
	
	return 0;
}