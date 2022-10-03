#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

struct Fenwick{
	unordered_map<int, ll> fen;
	void add(int pos, ll val){
		for (pos+=2e8+10; pos<inf; pos+=pos&-pos) fen[pos]+=val;
	}
	ll get(int pos){
		ll res=0;
		for (pos+=2e8+10; pos; pos-=pos&-pos) res+=fen[pos];
		return res;
	}
} fen1, fen2;

ll n, m, k, u, v, x, y, t, a, b, ans;
pll A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i].first;
	for (int i=1; i<=n; i++) cin>>A[i].second;
	sort(A+1, A+n+1);
	for (int i=1; i<=n; i++){
		ll x=A[i].first, v=A[i].second;
		ans+=x*fen1.get(v);
		ans-=fen2.get(v);
//		debug(x*fen1.get(v)-fen2.get(v))
//		debug2(x*fen1.get(v),fen2.get(v))
		fen1.add(v, +1);
		fen2.add(v, x);
	}
	cout<<ans<<'\n';
	
	return 0;
}