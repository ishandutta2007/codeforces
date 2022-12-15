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
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=2010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, root;
int A[MAXN], par[MAXN];
pll B[MAXN];
vector<pii> out;

int getpar(int x){ return (par[x]==x?x:par[x]=getpar(par[x]));}
pll operator -(pll X, pll Y){ return {X.first-Y.first, X.second-Y.second};}
ll Cross(pll X, pll Y){ return X.first*Y.second-X.second*Y.first;}

bool cmp(int i, int j){
	return Cross(B[root]-B[i], B[root]-B[j])<0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>B[i].first>>B[i].second>>A[i];
		par[i]=i;
	}
	vector<int> vec;
	for (int i=1; i<=n; i++) if (A[i]!=i){
		par[getpar(i)]=getpar(A[i]);
		vec.pb(i);
	}
	if (vec.empty()) kill(0)
	sort(all(vec), [](int i, int j){
		return B[i]<B[j];
	});
	root=vec.back();
	vec.pop_back();
	assert(vec.size());
	sort(all(vec), cmp);
	for (int i=1; i<vec.size(); i++){
		int x=vec[i], y=vec[i-1];
		if (getpar(x)!=getpar(y)){
			swap(A[x], A[y]);
			out.pb({x, y});
			par[getpar(x)]=getpar(y);
		}
	}
	while (A[root]!=root){
		out.pb({A[root], root});
		swap(A[root], A[A[root]]);
	}
	cout<<out.size()<<"\n";
	for (pii p:out) cout<<p.first<<" "<<p.second<<"\n";
	
	return 0;
}