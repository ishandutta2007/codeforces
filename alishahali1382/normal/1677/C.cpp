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
const int MAXN=200010;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], B[MAXN], C[MAXN];
int nex[MAXN], mark[MAXN];
vector<vector<int>> cycles;

int Main(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) cin>>B[i], nex[A[i]]=B[i], mark[i]=0;
	cycles.clear();
	
	int L=1, R=n;
	
//	for (int i=1; i<=n; i++) if (!mark[i]){
//		vector<int> vec;
//		int v=i;
//		while (!mark[v]){
//			vec.pb(v);
//			v=nex[v];
//		}
//		if (SZ(vec)%2==0){
//			for (int j=0; j<SZ(vec); j+=2){
//				C[vec[j]]=L++;
//				C[vec[j+1]]=R--;
//			}
//		}
//		else{
//			cycles.pb(vec);
//		}
//	}
	
	int odd=0;
	for (int i=1; i<=n; i++) if (!mark[i]){
		int v=i, t=0;
		while (!mark[v]){
			mark[v]=1;
			v=nex[v];
			t++;
		}
		odd+=(t&1);
	}
	
	int k=(n-odd)/2;
	ll ans=0;
	for (int i=1; i<=k; i++) ans+=(n-i+1)-i;
	cout<<ans*2<<"\n";
	
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
2 2
1100


*/