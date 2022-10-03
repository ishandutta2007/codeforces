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

short f(char ch){
	if (ch=='R') return 0;
	if (ch=='G') return 1;
	if (ch=='B') return 2;
}

int n, k, u, v, x, y, t, a, ans;
int A[MAXN];
int ps[MAXN];
char ch;

int solve(){
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>ch, A[i]=f(ch);
	ans=k;
	for (int j=0; j<3; j++){
		for (int i=1; i<=n; i++) ps[i]=ps[i-1]+(A[i]!=(i+j)%3);
		for (int i=k; i<=n; i++) ans=min(ans, ps[i]-ps[i-k]);
	}
	kill(ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;cin>>T;
	while (T--) solve();
	
	
	
	return 0;
}