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
const int MAXN = 300010, LOG=20;

pii operator +(pii i, pii j){
	return {min(i.first, j.first), max(i.second, j.second)};
}

struct Segment{
	pii seg[MAXN<<2];
	Segment(){
		seg[0]={inf, -inf};
	}
	pii Build(int id, int tl, int tr, pii A[]){
		if (tr-tl==1) return seg[id]=A[tl];
		int mid=(tl+tr)>>1;
		return seg[id]=Build(id<<1, tl, mid, A) + Build(id<<1 | 1, mid, tr, A);
	}
	
	pii Get(int id, int tl, int tr, int l, int r){
		if (r<=tl || tr<=l) return seg[0];
		if (l<=tl && tr<=r) return seg[id];
		int mid=(tl+tr)>>1;
		return Get(id<<1, tl, mid, l, r) + Get(id<<1 | 1, mid, tr, l, r);
	}
} seg[LOG];

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
pii dp[LOG][MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	if (n==1) kill(0)
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=0; i<3*n; i++) dp[0][i]={max(i-A[i%n], 0), min(3*n, i+A[i%n]+1)};
	seg[0].Build(1, 0, 3*n, dp[0]);
	//debugp(dp[0][1][0])
	
	for (int k=1; k<LOG; k++){
		for (int i=0; i<3*n; i++){
			int l=dp[k-1][i].first, r=dp[k-1][i].second;
			dp[k][i]=seg[k-1].Get(1, 0, 3*n, l, r);
		}
		seg[k].Build(1, 0, 3*n, dp[k]);
	}
		
	for (int i=n; i<2*n; i++){
		int l=i, r=i+1, res=0;
		for (int i=LOG-1; ~i; i--){
			pii p=seg[i].Get(1, 0, 3*n, l, r);
			if (p.second-p.first>=n) continue ;
			res|=(1<<i);
			l=p.first, r=p.second;
		}
		cout<<res+1<<' ';
	}
	
	
	return 0;
}