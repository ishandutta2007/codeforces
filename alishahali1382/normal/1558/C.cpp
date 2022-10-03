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
const int MAXN=2050, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
vector<int> out;

inline int Find(int x){
	for (int i=1; i<=n; i++) if (A[i]==x) return i;
	assert(0);
}
inline void Apply(int x){
	out.pb(x);
	reverse(A+1, A+x+1);
	assert(x&1);
}
int Main(){
	out.clear();
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) if ((A[i]+i)&1) kill(-1) 
	for (int x=n; x>1; x-=2){
//		debug(x)
//		for (int i=1; i<=n; i++) cerr<<A[i]<<" \n"[i==n];
		int pos=Find(x);
		if (pos!=1) Apply(pos);
		pos=Find(x-1);
//		debug(pos)
		if (pos!=2){
			Apply(pos-1);
			Apply(pos+1);
			Apply(3);
		}
		Apply(x);
	}
	for (int i=1; i<=n; i++) assert(A[i]==i);
	cout<<SZ(out)<<"\n";
	for (int i:out) cout<<i<<" ";
	cout<<"\n";
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
/*
1
5
3 4 5 2 1

*/