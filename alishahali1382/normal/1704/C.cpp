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
int A[MAXN], B[MAXN];

int Main(){
	ans=0;
	cin>>n>>m;
	for (int i=0; i<m; i++) cin>>A[i], A[i]--;
	if (m==1) kill(2)
	if (m==n) kill(n)
	sort(A, A+m);
	for (int i=0; i<m; i++) B[i]=(n+A[(i+1)%m]-A[i])%n-1;
	sort(B, B+m);
	reverse(B, B+m);
//	t=0;
//	k=0;
//	for (int i=0; i<m; i++){
//		B[i]-=2*t;
//		if (B[i]<=0) break ;
//		B[i]--;
//		ans++;
//		k++;
//		t++;
//	}
//	debug(k)
//	for (int i=0; i<k; i++) B[i]-=k-i;
//	
//	sort(B, B+m);
//	reverse(B, B+m);
//	t=0;
//	for (int i=0; i<k; i++){
//		B[i]-=t;
//		if (B[i]<=0) break ;
//		ans+=B[i];
//		t++;
//	}
	ans=1;
	ll sum=0;
	for (int k=1; k<=m; k++){
		sum+=B[k-1];
		ll val = sum-k*(k-1ll)-1ll*k*k;
		if (k<m && B[k]-4*k>0) val++;
		if (val<0) break ;
		ans=max(ans, (int)val);
	}
	kill(n-ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
10 5
2 4 6 8 10

*/