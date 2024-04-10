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
const int MAXN = 210, SGM=26;

struct Matrix{
	ll M[MAXN][MAXN];
	Matrix(){
		memset(M, -63, sizeof(M));
	}
	ll* operator [](int i){
		return M[i];
	}
};

Matrix operator *(Matrix &A, Matrix &B){
	Matrix Res;
	for (int i=0; i<MAXN; i++) for (int k=0; k<MAXN; k++) for (int j=0; j<MAXN; j++) Res[i][j]=max(Res[i][j], A[i][k] + B[k][j]);
	return Res;
}

Matrix operator ^(Matrix A, ll tav){
	Matrix Ans;
	for (int i=0; i<MAXN; i++) Ans[i][i]=0;
	for (; tav; tav>>=1, A=A*A) if (tav&1) Ans=Ans*A;
	return Ans;
}

ll n, m, k, u, v, x, y, t, a, b, ans;
int F[MAXN];
int C[MAXN][SGM], ts;
int sum[MAXN];
int A[MAXN];
string S[MAXN];

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
		sum[v]+=sum[F[v]];
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
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) cin>>S[i], sum[AddTrie(S[i])]+=A[i];
	BuildAho();
	
	Matrix T;
	for (int i=0; i<=ts; i++) for (int j=0; j<SGM; j++) T[i][C[i][j]]=sum[C[i][j]];
	T=T^m;
	
	for (int i=0; i<=ts; i++) ans=max(ans, T[0][i]);
	cout<<ans<<'\n';
	
	return 0;
}