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
int A[MAXN], B[MAXN];
vector<int> out;
set<int> st;
set<int> bad;

int nxt(int x){
	auto it=st.upper_bound(x);
	if (it==st.end()) it=st.begin();
	return *it;
}
int prv(int x){
	auto it=st.lower_bound(x);
	if (it==st.begin()) it=st.end();
	return *--it;
}

int Solve(){
	st.clear();
	bad.clear();
	out.clear();
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], B[i]=1, st.insert(i);
	for (int i=2; i<=n; i++) if (__gcd(A[i-1], A[i])==1) bad.insert(i);
	if (__gcd(A[1], A[n])==1) bad.insert(1);
	int curr=1;
	while (bad.size()){
//		debug(bad.count(1))
		auto it=bad.upper_bound(curr);
		if (it==bad.end()) it=bad.begin();
		int x=*it;
		out.pb(x);
		if (st.size()==1) break ;
		bad.erase(it);
		int a=prv(x), b=nxt(x);
		bad.erase(b);
		if (__gcd(A[a], A[b])==1) bad.insert(b);
		st.erase(x);
		curr=b;
	}
	cout<<out.size()<<" ";
	for (int i:out) cout<<i<<" ";cout<<"\n";
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
/*
1
5
5 9 2 10 15

1
2
1 2

1
6
1 2 4 2 4 2


*/