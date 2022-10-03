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
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], ans[MAXN];
int L[MAXN], R[MAXN];
vector<int> vec[MAXN];

inline void add(int l, int r){
	if (l>r) return ;
	ans[l]++;
	ans[r+1]--;
}

int Solve(){
	cin>>n;
	for (int i=1; i<=n; i++) ans[i]=0, vec[i].clear();
	for (int i=1; i<=n; i++) cin>>A[i], vec[A[i]].pb(i);
	for (int i=1; i<=n; i++) for (L[i]=i-1; L[i] && A[L[i]]>=A[i]; L[i]=L[L[i]]);
	for (int i=n; i; i--) for (R[i]=i+1; R[i]<=n && A[R[i]]>A[i]; R[i]=R[R[i]]);
	for (int x=1; x<=n; x++){
		if (vec[x].empty()){
			add(1, n-x+1);
			continue ;
		}
		int mx=1;
		for (int i:vec[x]) mx=max(mx, R[i]-L[i]-1);
		add(mx+1, n-x+1);
//		debug2(x, mx)
	}
	
	for (int i=1; i<=n; i++){
		ans[i]+=ans[i-1];
		cout<<(ans[i]==0);
	}
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int Test;
	cin>>Test;
	while (Test--) Solve();
	
	return 0;
}