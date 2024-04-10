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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 500010, LOG=20;

struct SEGMENT{
	pii seg[MAXN<<2];
	
	pii build(int id, int tl, int tr){
		if (tr-tl<2) return seg[id]={0, tl};
		int mid=(tl+tr)>>1;
		return seg[id]=max(build(id<<1, tl, mid), build(id<<1 | 1, mid, tr));
	}
	
	void Set(int id, int tl, int tr, int pos, int val){
		if (pos<tl || tr<=pos) return ;
		if (tr-tl<2){
			seg[id].first=val;
			return ;
		}
		int mid=(tl+tr)>>1;
		Set(id<<1, tl, mid, pos, val);
		Set(id<<1 | 1, mid, tr, pos, val);
		seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
	}
	
	pii Get(int id, int tl, int tr, int l, int r){
		if (r<=tl || tr<=l) return {0, 0};
		if (l<=tl && tr<=r) return seg[id];
		int mid=(tl+tr)>>1;
		return max(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
	}
} dp, seg;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int prv[MAXN];
pii mx[MAXN];
vector<int> vec[MAXN];
vector<int> par[MAXN];
unordered_map<int, int> last;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		prv[i]=last[A[i]];
		last[A[i]]=i;
		vec[prv[i]].pb(i);
	}
	seg.build(1, 1, n+1);
	dp.build(1, 1, n+1);
	for (int i=1; i<=n; i++){
		for (int j:vec[i]){
			pii p=seg.Get(1, 1, n+1, i+1, j);
			mx[j]=p;
		}
		for (int j:vec[i]) seg.Set(1, 1, n+1, j, i);
	}
	
	for (int i=1; i<=n; i++){
		int tmp=prv[prv[prv[i]]];
		pii p=dp.Get(1, 1, n+1, 1, tmp);
		int val=(p.first+4)*(tmp>0);
		if (tmp) par[i]={p.second, tmp, prv[prv[i]], prv[i]};
				
		tmp=mx[i].first;
		p=dp.Get(1, 1, n+1, 1, tmp);
		if ((p.first+4)*(tmp>0)>val){
			val=(p.first+4)*(tmp>0);
			par[i]={p.second, tmp, prv[i], mx[i].second};
		}
		dp.Set(1, 1, n+1, i, val);
	}
	
	pii p=dp.Get(1, 1, n+1, 1, n+1);
	cout<<p.first<<'\n';
	int last=p.second;
	
	vector<int> out;
	for (; last; last=par[last][0]){
		if (par[last].empty()) break ;
		out.pb(A[last]);
		out.pb(A[par[last][3]]);
		out.pb(A[par[last][2]]);
		out.pb(A[par[last][1]]);
	}
	reverse(all(out));
	for (int i:out) cout<<i<<' ';
	
	return 0;
}