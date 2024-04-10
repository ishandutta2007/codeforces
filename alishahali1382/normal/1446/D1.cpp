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
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=400010, LOG=20;

int n, m, k, u, v, X, t, a, b, ans;
int A[MAXN], B[MAXN];
int mn[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], B[A[i]]++;
	for (int i=1; i<=n; i++) if (B[i]>B[X]) X=i;
	for (int y=1; y<=100; y++) if (y!=X){
		B[0]=n;
		for (int i=1; i<=n; i++){
			B[i]=0;
			if (A[i]==X) B[i]=-1;
			if (A[i]==y) B[i]=+1;
			B[i]+=B[i-1];
		}
		memset(mn, 31, sizeof(mn));
		for (int i=0; i<=n; i++) mn[B[i]]=min(mn[B[i]], i);
		for (int i=1; i<=2*n; i++) mn[i]=min(mn[i], mn[i-1]);
		for (int i=1; i<=n; i++) ans=max(ans, i-mn[B[i]]);
	}
	cout<<ans<<"\n";
	
	return 0;
}