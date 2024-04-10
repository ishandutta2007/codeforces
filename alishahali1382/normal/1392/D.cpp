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
const int MAXN=200010, LOG=20;

int n, m, u, v, x, y, t, a, b, ans;
char A[MAXN];
int R1[MAXN], R2[MAXN];
int L1[MAXN], L2[MAXN];

int Solve(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	ans=n;
	for (int shit:{0, 1}){
		for (int t:{1, 2}){
			fill(R1, R1+n, inf);
			fill(R2, R2+n, inf);
			fill(L1, L1+n, inf);
			fill(L2, L2+n, inf);
			R1[t+1]=(A[t+1]=='L');
			for (int i=1; i<=t; i++) R1[t+1]+=(A[i]=='R');
			for (int i=t+2; i<=n; i++){
				R1[i]=min(L1[i-1], L2[i-1]) + (A[i]=='L');
				R2[i]=R1[i-1] + (A[i]=='L');
				L1[i]=min(R1[i-1], R2[i-1]) + (A[i]=='R');
				L2[i]=L1[i-1] + (A[i]=='R');
			}
			if (t==0) ans=min({ans, R1[n], L1[n], L2[n]});
			if (t==1) ans=min({ans, L1[n], R1[n], R2[n]});
			if (t==2) ans=min({ans, R1[n], R2[n]});
		}
		for (int i=1; i<=n; i++) A[i]='L'+'R'-A[i];
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}