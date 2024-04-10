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
const int MAXN=1000010, LOG=20;

ll w;
int n, m, k, u, v, x, y, t, a, b;
int f[MAXN], A[MAXN];
int cnt[MAXN], mark[MAXN];

int Solve(int T){
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		A[i]=f[A[i]];
		if (mark[A[i]]!=T) mark[A[i]]=T, cnt[A[i]]=0;
		cnt[A[i]]++;
	}
	int ans0=0, ans1=0;
	for (int i=1; i<=n; i++) ans0=max(ans0, cnt[A[i]]);
	for (int i=1; i<=n; i++) if (cnt[A[i]]%2==0) A[i]=1;
	for (int i=1; i<=n; i++) cnt[A[i]]=0;
	cnt[1]=0;
	for (int i=1; i<=n; i++) cnt[A[i]]++;
	for (int i=1; i<=n; i++) ans1=max(ans1, cnt[A[i]]);
	cin>>m;
	while (m--){
		cin>>w;
		if (w>=1) cout<<ans1<<"\n";
		else cout<<ans0<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<MAXN; i++) f[i]=i;
	for (int i=1000; i; i--) for (int j=i*i; j<MAXN; j+=i*i) if (f[j]%(i*i)==0) f[j]/=i*i;
	int T;
	cin>>T;
	while (T--) Solve(T);
	
	return 0;
}
/*
1
5 4
2 3 4 3 2
3 5 12 20

*/