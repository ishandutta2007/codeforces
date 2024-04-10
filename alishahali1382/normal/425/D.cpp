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
const int MAXN=100010, SQ=330;

int n, m, k, u, v, x, y, t, a, b, ans;
int deg[MAXN*2], X[MAXN], Y[MAXN], dead[MAXN];
vector<int> V[MAXN*2], vec;
unordered_set<int> shit[MAXN];

inline bool get(int x, int y){
	if (x<0 || x>=MAXN) return 0;
	return shit[x].count(y);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>X[i]>>Y[i];
		V[X[i]].pb(i);
		V[Y[i]+MAXN].pb(i);
		deg[X[i]]++;
		deg[MAXN+Y[i]]++;
		shit[X[i]].insert(Y[i]);
	}
	for (int y=0; y<MAXN; y++) if (deg[MAXN+y]<SQ){
		vec=V[MAXN+y];
		for (int i=0; i<deg[MAXN+y]; i++) for (int j=0; j<i; j++){
			int x1=X[vec[i]], x2=X[vec[j]], ln=abs(x1-x2);
			ans+=(get(x1, y-ln) && get(x2, y-ln));
			ans+=(get(x1, y+ln) && get(x2, y+ln));
		}
		for (int i:vec) shit[X[i]].erase(Y[i]), dead[i]=1, deg[X[i]]--;
		deg[MAXN+y]=0;
	}
	for (int x=0; x<MAXN; x++){
		vec.clear();
		for (int i:V[x]) if (!dead[i]) vec.pb(i);
		assert(deg[x]<350);
		for (int i=0; i<deg[x]; i++) for (int j=0; j<i; j++){
			int y1=Y[vec[i]], y2=Y[vec[j]], ln=abs(y1-y2);
			ans+=(get(x-ln, y1) && get(x-ln, y2));
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
/*
4
0 0
0 1
1 0
1 1

*/