#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
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
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN], C[MAXN];

void Solve(int *B){
	ll res=0, sum=0;
	for (int i=1; i<=n; i++){
		sum+=A[i]-B[i];
		res+=abs(sum);
	}
	ans=min(ans, res);
}

int Main(){
	cin>>n;
	k=0;
	for (int i=1; i<=n; i++) cin>>A[i], A[i]&=1, k+=A[i];
	if (k!=n/2 && k!=(n+1)/2) kill(-1)
	ans=INF;
	if (k==(n+1)/2) Solve(B);
	if (k==n/2) Solve(C);
	
	kill(ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<MAXN; i++) B[i]=(i%2==1), C[i]=(i%2==0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}