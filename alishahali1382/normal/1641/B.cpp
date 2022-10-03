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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
vector<pii> out;
vector<int> out2;
map<int, int> cnt;

void Rev(int x){ // reverse [x...n]
	for (int i=n; i>=x; i--) out.pb({x-1+n-i, A[i]});
	reverse(A+x, A+n+1);
	out2.pb(2*(n-x+1));
}

int Main(){
	cnt.clear();
	out.clear();
	out2.clear();
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], cnt[A[i]]^=1;
	for (pii p:cnt) if (p.second) kill(-1)
	
	for (int i=n-1; i; i--){
		int pos=-1;
		for (int j=i+1; j<=n && pos==-1; j++) if (A[j]==A[i]) pos=j;
		if (pos==-1) continue ;
//		debug2(i, pos)
		Rev(i);
		Rev(n+i-pos+1);
	}
//	for (int i=1; i<=n; i++) cerr<<A[i]<<" \n"[i==n];
	
	cout<<SZ(out)<<"\n";
	for (pii p:out) cout<<p.first<<" "<<p.second<<"\n";
	int last=n+1;
	for (int i=n; i; i--){
		if (i==1 || A[i]!=A[i-1]){
			out2.pb(last-i);
			last=i;
		}
	}
	reverse(all(out2));
	cout<<SZ(out2)<<"\n";
	for (int x:out2) cout<<x<<" ";
	cout<<"\n";
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
2
5 5

*/