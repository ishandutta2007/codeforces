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
const int MAXN=510, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], sz[MAXN], dead[MAXN];
vector<int> vec, shit;
vector<pii> out;

inline int ask(vector<int> S, vector<int> T, int v){
	if (S.empty() || T.empty()) return 0;
	cout<<S.size()<<endl;
	for (int x:S) cout<<x<<" ";cout<<endl;
	cout<<T.size()<<endl;
	for (int x:T) cout<<x<<" ";cout<<endl;
	cout<<v<<endl;
	int x;
	cin>>x;
	return x;
}
void divide(int tl, int tr, int ted, int v){
	if (!ted) return ;
	if (tr-tl==1){
		out.pb({v, vec[tl]});
		dead[vec[tl]]=1;
		return ;
	}
	int mid=(tl+tr)>>1;
	vector<int> tmp;
	for (int i=tl; i<mid; i++) tmp.pb(vec[i]);
	int x=ask(shit, tmp, v);
	divide(tl, mid, x, v);
	divide(mid, tr, ted-x, v);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	shit={1};
	cin>>n;
	for (int i=2; i<=n; i++) vec.pb(i);
	for (int i=2; i<=n; i++) sz[i]=ask({1}, vec, i);
	for (int i=1; i<=n; i++) A[i]=i;
	sz[1]=n;
	sort(A+1, A+n+1, [](int i, int j){
		return sz[i]<sz[j];
	});
	for (int i=1; i<n; i++){
		vec.clear();
		for (int j=1; j<i; j++) if (!dead[A[j]]) vec.pb(A[j]);
		int v=A[i];
		int ted=ask(vec, {1}, v);
		divide(0, vec.size(), ted, v);
	}
	for (int i=2; i<=n; i++) if (!dead[i]) out.pb({1, i});
	cout<<"ANSWER"<<endl;
	for (pii p:out) cout<<p.first<<" "<<p.second<<endl;
	
	return 0;
}