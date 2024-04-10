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
const int N=25, MAXN=N*50001;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[2*N];
int B[2][MAXN];
ll dp[N][MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<2*n; i++) cin>>A[i];
	sort(A, A+2*n);
	reverse(A, A+2*n);
	n--;
	B[0][n]=A[2*n];
	B[1][n]=A[2*n+1];
	
	ll sum=0;
	for (int i=0; i<2*n; i++){
		sum+=A[i];
		for (int j=n; j; j--) for (int x=A[i]; x<MAXN; x++) if (dp[j-1][x-A[i]]) dp[j][x]=dp[j-1][x-A[i]]|(1ll<<i);
		dp[1][A[i]]=(1ll<<i);
	}
	
	ll mask;
	for (int i=sum; i>=sum-i; i--) if (dp[n][i]) mask=dp[n][i];
	
	int x=0, y=0;
	for (int i=0; i<2*n; i++){
		if (mask&(1ll<<i)) B[0][x++]=A[i];
		else B[1][y++]=A[i];
	}
	
	n++;
	sort(B[0], B[0]+n);
	sort(B[1], B[1]+n);
	reverse(B[1], B[1]+n);
	
	for (int i:{0, 1}){
		for (int j=0; j<n; j++) cout<<B[i][j]<<' ';
		cout<<'\n';
	}
	
	return 0;
}