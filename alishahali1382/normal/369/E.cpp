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
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, cnt, ans;
vector<int> vec[MAXN];
vector<int> seg[4*MAXN];

void build(int id, int tl, int tr){
	for (int i=tl; i<=tr; i++) for (int x:vec[i]) seg[id].pb(x);
	sort(all(seg[id]));
	if (tl==tr) return ;
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid+1, tr);
}

int get(int id, int tl, int tr, int l, int r, int val){
	if (r<tl || tr<l) return 0;
	if (l<=tl && tr<=r) return lower_bound(all(seg[id]), val)-seg[id].begin();
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r, val) + get(id<<1 | 1, mid+1, tr, l, r, val);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>x>>y;
		vec[x].pb(y);
	}
	build(1, 1, MAXN-1);
	while (m--){
		cin>>cnt>>x;
		ans=get(1, 1, MAXN-1, 1, x-1, x);
		for (int i=2; i<=cnt; i++){
			cin>>y;
			ans+=get(1, 1, MAXN-1, x+1, y-1, y);
			x=y;
		}
		ans+=get(1, 1, MAXN-1, x+1, MAXN-1, MAXN);
		cout<<n-ans<<'\n';
	}
	
	return 0;
}