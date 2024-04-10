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
const int inf=1000000000;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

struct MINSEG{
	int seg[MAXN<<2];
	MINSEG(){ memset(seg, 31, sizeof(seg));}
	void update(int id, int tl, int tr, int pos, int val){
		if (pos<tl || tr<pos) return ;
		if (tl==tr){
			seg[id]=val;
			return ;
		}
		int mid=(tl+tr)>>1;
		update(id<<1, tl, mid, pos, val);
		update(id<<1 | 1, mid+1, tr, pos, val);
		seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
	}
	int get(int id, int tl, int tr, int l, int r){
		if (r<tl || tr<l) return inf;
		if (l<=tl && tr<=r) return seg[id];
		int mid=(tl+tr)>>1;
		return min(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid+1, tr, l, r));
	}
} minseg;

struct SUMSEG{
	int seg[MAXN<<2];
	SUMSEG(){ memset(seg, 0, sizeof(seg));}
	void update(int id, int tl, int tr, int pos, int val){
		if (pos<tl || tr<pos) return ;
		if (tl==tr){
			seg[id]=val;
			return ;
		}
		int mid=(tl+tr)>>1;
		update(id<<1, tl, mid, pos, val);
		update(id<<1 | 1, mid+1, tr, pos, val);
		seg[id]=seg[id<<1] + seg[id<<1 | 1];
	}
	int get(int id, int tl, int tr, int l, int r){
		if (r<tl || tr<l) return 0;
		if (l<=tl && tr<=r) return seg[id];
		int mid=(tl+tr)>>1;
		return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid+1, tr, l, r);
	}
} sumseg;

int n, m, k, u, v, l, r, t, a, b;
int A[MAXN];
int prv[MAXN];
int ans1[MAXN], ans2[MAXN];
vector<int> last[MAXN];
vector<pii> query[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>l>>r;
		query[r].pb({l, i});
	}
	
	for (int i=1; i<=n; i++){
		if (!last[A[i]].empty()) sumseg.update(1, 1, n, last[A[i]].back(), 0);
		sumseg.update(1, 1, n, i, 1);
		prv[i]=i;
		if (last[A[i]].size()<=1) prv[i]=0;
		else{
			if (last[A[i]][last[A[i]].size()-1]-last[A[i]][last[A[i]].size()-2]==i-last[A[i]][last[A[i]].size()-1]) prv[i]=prv[last[A[i]][last[A[i]].size()-1]];
			else prv[i]=last[A[i]][last[A[i]].size()-2]+1;
		}
		if (!last[A[i]].empty()) minseg.update(1, 1, n, last[A[i]].back(), inf);
		minseg.update(1, 1, n, i, prv[i]);
		last[A[i]].pb(i);
		
		for (pii p:query[i]){
			ans1[p.second]=sumseg.get(1, 1, n, p.first, i);
			ans2[p.second]=(minseg.get(1, 1, n, p.first, i)<=p.first);
		}
	}
	
	for (int i=1; i<=m; i++) cout<<ans1[i]-ans2[i]+1<<'\n';
	
	return 0;
}