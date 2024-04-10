#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans=inf;
int A[MAXN], posa[MAXN];
int B[MAXN], posb[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], posa[A[i]]=i;
	for (int i=1; i<=n; i++) cin>>B[i], posb[B[i]]=i;
	
	ans=2*n;
	
	bool f=posb[1];
	for (int i=posb[1]; i<=n; i++) f&=(B[i]==i-posb[1]+1);
	if (f){
		for (int i=B[n]+1; i<=n; i++) if (posb[i] && posb[i]>i-B[n]-1) f=0;
		if (f) ans=min(ans, n-B[n]);
	}
	
	debug(ans)
	
	if (posa[1]){
		int res=0;
		for (int i=1; i<=n; i++) res=max(res, posb[i]-i+1);
		ans=min(ans, n+res);
	}
		
	if (posb[1]){
		int res=posb[1];
		for (int i=2; i<=n; i++) if (posb[i]>res) res=max(res, posb[i]-i+1);
		ans=min(ans, res+n);
	}
	cout<<ans<<'\n';
	
	return 0;
}