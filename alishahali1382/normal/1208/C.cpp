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
const int MAXN = 1010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, cur;
int A[MAXN][MAXN];

void go(int i, int j){
	A[i][j]=8+cur; A[i][j+1]=9+cur; A[i][j+2]=1+cur; A[i][j+3]=13+cur;
	A[i+1][j]=3+cur; A[i+1][j+1]=12+cur; A[i+1][j+2]=7+cur; A[i+1][j+3]=5+cur;
	A[i+2][j]=0+cur; A[i+2][j+1]=2+cur; A[i+2][j+2]=4+cur; A[i+2][j+3]=11+cur;
	A[i+3][j]=6+cur; A[i+3][j+1]=10+cur; A[i+3][j+2]=15+cur; A[i+3][j+3]=14+cur;
	cur+=16;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i+=4) for (int j=0; j<n; j+=4) go(i, j);
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) cout<<A[i][j]<<" \n"[j==n-1];
	
	
	return 0;
}