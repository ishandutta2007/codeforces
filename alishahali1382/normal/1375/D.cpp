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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int N=300010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N], mark[N];
vector<int> out;

int Solve(){
	out.clear();
	cin>>n;
	for (int i=0; i<n; i++) cin>>A[i];
	while (1){
		int mex=0;
		for (int i=0; i<n; i++) mark[i]=0;
		for (int i=0; i<n; i++) mark[A[i]]=1;
		while (mark[mex]) mex++;
		if (mex<n){
			A[mex]=mex;
			out.pb(mex);
			continue ;
		}
		int bad=-1, pos;
		for (int i=0; i<n; i++) if (A[i]!=i) bad=i;
		if (bad==-1) break ;
		for (int i=0; i<n; i++) if (A[i]==bad) pos=i;
		A[pos]=n;
		out.pb(pos);
	}
	cout<<out.size()<<"\n";
	for (int i:out) cout<<i+1<<' ';cout<<"\n";
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