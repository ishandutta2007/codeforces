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
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, L, R;
ll A[MAXN];
int cnt[MAXN];
bool mark[MAXN];
bool check(int l, int r){          //    [l, r]
	memset(cnt, 0, sizeof(cnt));
	memset(mark, 0, sizeof(mark));
	for (int i=l; i<=r; i++) cnt[A[i]]++;
	for (int i=1; i<=n; i++){
		if (l<=i && i<=r || l<=n-i+1 && n-i+1<=r) continue ;
		if (A[i]!=A[n-i+1]) return 0;
	}
	for (int i=l; i<=r; i++){
		if (mark[i]) continue ;
		if (l<=n-i+1 && n-i+1<=r) continue ;
		if (!cnt[A[n-i+1]]) return 0;
		cnt[A[n-i+1]]--;
		mark[i]=1;
		mark[n-i+1]=1;
	}
	int odd=0;
	for (int i=1; i<=n; ++i) odd+=cnt[i]&1;
	if (odd>(n&1)) return 0;
	return 1;
}

ll solve(){
	ll dwn=L-1, up=R;
	while (up-dwn>1){
		int mid=(dwn+up)/2;
		if (check(L, mid)) up=mid;
		else dwn=mid;
	}
	for (int i=max(dwn-5, 0ll); i<min(up+5, n); i++) if (check(L, i)) return i;
	return up;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], cnt[A[i]]++;
	for (int i=1; i<=n; i++) t+=cnt[i]&1;
	if (t>=2) kill(0)
	L=1;
	R=n;
	while (A[L]==A[R] && L<=R){
		L++;
		R--;
	}
	if (L>=R) kill(n*(n+1)/2)
	
	a=solve();
	//debug(a)
	
	reverse(A+1, A+n+1);
	b=solve();
	//debug(b)
	
	ll ans=-L*L + L*((n-a+1) + (n-b+1));
	cout<<ans<<'\n';
	
	return 0;
}