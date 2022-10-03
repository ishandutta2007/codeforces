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

ll n, m, k, u, v, x, y, t, a, b, ans, bad;
ll A[MAXN];
map<int, int> cnt;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], cnt[A[i]]++;
	
	for (pii p:cnt){
		if (p.second>2) kill("cslnb")
		if (p.second==2) t++, bad=p.first;
	}
	if (t>1 || t==1 && bad==0) kill("cslnb")
	
	if (t){
		for (int i=1; i<=n; i++) if (A[i]==bad){
			A[i]--;
			break ;
		}
		sort(A+1, A+n+1);
		for (int i=2; i<=n; i++) if (A[i]==A[i-1]) kill("cslnb")
	}
	debug(t)
	
	sort(A+1, A+n+1);
	for (int i=1; i<=n; i++) ans+=A[i]-(i-1);
	ans+=t;
	if (ans&1) kill("sjfnb")
	kill("cslnb")
	
	return 0;
}