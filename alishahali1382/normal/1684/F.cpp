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
#define debugv(v) {cerr<<#v<<" : ";for (auto abcd:v) cerr<<abcd<<' ';cerr<<endl;}
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
int A[MAXN], R[MAXN], last[MAXN];
vector<int> vec[MAXN], comp;

int Main(){
	comp.clear();
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], comp.pb(A[i]), R[i]=i;
	while (m--){
		cin>>x>>y;
		R[x]=max(R[x], y);
	}
	for (int i=2; i<=n; i++) R[i]=max(R[i], R[i-1]);
	
//	debug(R[1])
	
	ans=n;
	sort(all(comp));
	comp.resize(m=unique(all(comp))-comp.begin());
	for (int i=1; i<=m; i++) vec[i].clear(), last[i]=0;
	for (int i=1; i<=n; i++){
		A[i]=lower_bound(all(comp), A[i])-comp.begin()+1;
		vec[A[i]].pb(i);
	}
	
	int pref=n+1;
	for (int i=1; i<=n; i++){
		if (last[A[i]] && R[last[A[i]]]>=i){
			pref=i;
			break ;
		}
		last[A[i]]=i;
	}
	if (pref==n+1) kill(0)
	
//	debug(pref)
	
	int r=n;
	for (int l=pref; l; l--){
		while (l<r){
			int x=A[r];
			int pos=lower_bound(all(vec[x]), l)-vec[x].begin();
			if (pos){
				pos=vec[x][pos-1];
				if (R[pos]>=r) break ;
			}
			pos=upper_bound(all(vec[x]), r)-vec[x].begin();
			if (pos<SZ(vec[x])){
				pos=vec[x][pos];
				if (R[r]>=pos) break ;
			}
			r--;
		}
		ans=min(ans, r-l+1);
//		debug2(l, r)
	}
	
	
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
7 3
1 1 2 1 3 3 5
1 4
4 5
2 4


*/