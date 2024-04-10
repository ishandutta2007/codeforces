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
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
vector<pii> out;
set<int> st;

void apply(int x, int y){
	out.pb({x, y});
	swap(A[x], A[y]);
	A[x]*=-1;
	A[y]*=-1;
}
void cycle2(int v){
	while (A[v]>0) v=A[v];
//	debug(v)
	while (A[-A[v]]>0){
//		debug2(v, A[v])
//		debug(A[-A[v]])
		apply(v, -A[v]);
//		debug(A[v])
//		cerr<<"\n";
	}
	v=-A[v];
	while (A[-A[v]]>0){
		apply(v, -A[v]);
	}
	apply(v, -A[v]);
}
void cycle(int v){
	int a=v, b=A[v], c=A[A[v]];
	apply(a, b);
	apply(b, c);
	cycle2(a);
}
vector<int> getcycle(int v){
	vector<int> res={v};
	while (1){
		v=A[v];
		if (v==res[0]) break ;
		res.pb(v);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	/*
	n=10;
	A[1]=n;
	for (int i=2; i<=n; i++) A[i]=i-1;
	cycle(1);
	for (int i=1; i<=n; i++) debug2(i, A[i])
	*/
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		if (A[i]!=i) st.insert(i);
	}
	while (st.size()){
		int v=*st.begin();
		auto vec=getcycle(v);
		if (vec.size()==st.size()){
//			debug2("cycle", v)
			if (vec.size()>2) cycle(v);
			else{
				int i=1;
				while (A[i]!=i) i++;
				apply(i, v);
				cycle2(v);
			}
			break ;
		}
//		debugv(vec)
		for (int x:vec) st.erase(x);
		int u=*st.begin();
		auto vec2=getcycle(u);
//		debugv(vec2)
		for (int x:vec2) st.erase(x);
		apply(u, v);
		cycle2(v);
	}
	cout<<out.size()<<"\n";
	for (pii p:out) cout<<p.first<<" "<<p.second<<"\n";
	
	return 0;
}