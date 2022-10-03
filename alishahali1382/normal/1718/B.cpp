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
const int K=110, N=58;

int n, m, k, u, v, x, y, t, a, b, ans;
ll A[K];
ll fib[N];

int Main(){
	ll sum=0;
	cin>>k;
	for (int i=0; i<k; i++) cin>>A[i], sum+=A[i];
	n=0;
	while (sum+1>fib[n]) n++;
	if (fib[n]!=sum+1) kill("No")
	n-=2;
	int last=-1;
	for (int i=n; i; i--){
		int mx=-1;
		for (int j=0; j<k; j++) if (j!=last){
			if (mx==-1 || A[j]>A[mx]) mx=j;
		}
		if (mx==-1) kill("No")
		if (A[mx]<fib[i]) kill("No")
		A[mx]-=fib[i];
		last=mx;
	}
	kill("Yes")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fib[1]=1;
	for (int i=2; i<N; i++){
		fib[i]=fib[i-1]+fib[i-2];
//		debug2(i, fib[i])
	}
	
	int T;	
	cin>>T;
	while (T--) Main();
	
	return 0;
}