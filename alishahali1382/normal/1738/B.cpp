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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010;

int n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN], S[MAXN];

int Main(){
	cin>>n>>k;
	for (int i=n-k+1; i<=n; i++) cin>>S[i];
	if (k==1) kill("Yes")
	if (k==n){
		for (int i=1; i<=n; i++) A[i]=S[i]-S[i-1];
		for (int i=1; i<n; i++) if (A[i]>A[i+1]) kill("No")
		kill("Yes")
	}
	for (int i=n-k+2; i<=n; i++) A[i]=S[i]-S[i-1];
	for (int i=n-k+1; i>1; i--) A[i]=A[n-k+2], S[i-1]=S[i]-A[i];
	A[1]=S[1];
	for (int i=1; i<n; i++) if (A[i]>A[i+1]) kill("No")
	kill("Yes")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}