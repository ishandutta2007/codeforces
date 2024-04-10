#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int N=(1<<9);

int n, m, k, u, v, x, y, t, a, b;
ll A[N][N], ans[N][N];
int X[N], Y[N];

void SolveLine(ll *A, int n, ll *ans){
	if (n==1){
		ans[0]=A[0];
		return ;
	}
	int nn=(n>>1);
	ll AA[nn];
	for (int i=0; i<nn; i++) AA[i]=A[i]^A[i+nn];
	SolveLine(AA, nn, ans+nn);
	for (int i=0; i<nn; i++) AA[i]=A[i];
	for (int i=nn; i<n; i++) for (int j=0; j<k; j++){
		int pos=((i+Y[j])&(n-1));
		if (pos<nn) AA[pos]^=ans[i];
	}
	SolveLine(AA, nn, ans);
	for (int i=0; i<nn; i++) ans[i+nn]^=ans[i];
}
void SolveTable(ll A[][N], int n, int m, ll ans[][N]){
	if (n==1){
		SolveLine(A[0], m, ans[0]);
		return ;
	}
	int nn=(n>>1);
	ll AA[nn][N];
	for (int i=0; i<nn; i++) for (int j=0; j<m; j++) AA[i][j]=A[i][j]^A[i+nn][j];
	SolveTable(AA, nn, m, ans+nn);
	for (int i=0; i<nn; i++) for (int j=0; j<m; j++) AA[i][j]=A[i][j];
	for (int i=nn; i<n; i++) for (int j=0; j<m; j++) for (int t=0; t<k; t++){
		int x=((i+X[t])&(n-1)), y=((j+Y[t])&(m-1));
		if (x<nn) AA[x][y]^=ans[i][j];
	}
	SolveTable(AA, nn, m, ans);
	for (int i=0; i<nn; i++) for (int j=0; j<m; j++) ans[i+nn][j]^=ans[i][j];
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	n=(1<<n);
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin>>A[i][j];
	cin>>k;
	for (int i=0; i<k; i++) cin>>X[i]>>Y[i], X[i]--, Y[i]--;
	SolveTable(A, n, n, ans);
	
	int out=0;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) out+=(ans[i][j]>0);
	cout<<out<<"\n";

	return 0;
}
/*
2
5 5 5 5
2 6 2 3
0 0 2 0
0 0 0 0
5
1 1
1 2
1 3
1 4
2 4

*/