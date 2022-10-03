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

ll ans; // :))
int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], B[MAXN], C[MAXN];
int ted[MAXN], f[MAXN], g[MAXN];
int ps1[MAXN], ps2[MAXN];
int fen[MAXN];

inline void add(int pos, int val){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;
}
inline int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i]>>B[i];
		if (A[i]>B[i]) swap(A[i], B[i]);
		C[A[i]]=i;
		C[B[i]]=-i;
	}
	for (int i=1; i<=2*n; i++){
		if (C[i]<0) add(i, -1);
		else{
			ted[C[i]]+=get(B[C[i]])-get(i);
			f[C[i]]=get(2*n)-get(B[C[i]]);
			add(B[C[i]], +1);
		}
	}
	for (int i=2*n; i; i--){
		if (C[i]>0) add(i, -1);
		else{
			ted[-C[i]]+=get(i)-get(A[-C[i]]);
			add(A[-C[i]], +1);
		}
	}
	for (int i=2*n; i; i--) if (C[i]>0){
		g[C[i]]=get(B[C[i]]);
		add(B[C[i]], +1);
	}
	memset(fen, 0, sizeof(fen));
	
	for (int i=1; i<=n; i++){
//		debug2(i, ted[i])
		ans+=ted[i]*(n-1ll-ted[i]);
	}
	ans/=2;
//	debug(ans)
	ans=n*(n-1ll)*(n-2ll)/6-ans;
//	debug(ans)
	
	for (int i=1; i<=n; i++){
		ps1[A[i]]+=g[i];
		ps2[B[i]]+=g[i];
	}
	for (int i=1; i<=2*n; i++) ps2[i]+=ps2[i-1];
	for (int i=2*n; i; i--) ps1[i]+=ps1[i+1];
	for (int i=1; i<=n; i++){
		ans-=1ll*f[i]*g[i];
		ans-=ps1[B[i]];
		ans-=ps2[A[i]];
	}
	
	cout<<ans<<"\n";
	
	return 0;
}