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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
vector<int> out;

void Solve(int x, int y){
	n=x+y;
	int xx=(n+1)/2, yy=n/2;
	for (int i=0; i<=xx; i++){
		int j=x-xx+i;
//		debug2(xx, yy)
//		debug2(i, j)
//		cerr<<"\n";
		if (j<0 || j>yy) continue ;
		out.pb(i+j);
	}
}
int Main(){
	out.clear();
	cin>>x>>y;
	Solve(x, y);
	Solve(y, x);
	sort(all(out));
	out.resize(unique(all(out))-out.begin());
	cout<<SZ(out)<<"\n";
	for (int a:out) cout<<a<<" ";
	cout<<"\n";
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}