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
const int MAXN = 400010, LOG=20;

int n, m, k, u, v, t, a, b, ans;
pii seg[MAXN<<2];
set<int> point[MAXN];
vector<int> compress;
piii query[MAXN];
string s;

void build(int id, int tl, int tr){
	if (tl==tr){
		seg[id]={-1, tl};
		return ;
	}
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid+1, tr);
	seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
}

void update(int id, int tl, int tr, int pos, int val){
	if (tl==tr){
		seg[id]={val, pos};
		return ;
	}
	int mid=(tl+tr)>>1;
	if (pos<=mid) update(id<<1, tl, mid, pos, val);
	else update(id<<1 | 1, mid+1, tr, pos, val);
	seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
}

pii BS(int id, int tl, int tr, int l, int r, pii val){
	if (seg[id]<=val || r<tl || tr<l) return {-1, -1};
	if (tl==tr) return seg[id];
	int mid=(tl+tr)>>1;
	pii res=BS(id<<1, tl, mid, l, r, val);
	if (res==make_pair(-1, -1)) res=BS(id<<1 | 1, mid+1, tr, l, r, val);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>s>>query[i].first.first>>query[i].first.second;
		compress.pb(query[i].first.first);
		compress.pb(query[i].first.second);
		if (s=="add") query[i].second=0;
		if (s=="remove") query[i].second=1;
		if (s=="find") query[i].second=2;
	}
	compress.pb(-1);
	sort(all(compress));
	compress.resize(unique(all(compress))-compress.begin());
	
	for (int i=0; i<MAXN; i++) point[i].insert(-1);
	build(1, 0, MAXN-1);
	
	for (int i=1; i<=n; i++){
		int x=lower_bound(all(compress), query[i].first.first)-compress.begin(), y=lower_bound(all(compress), query[i].first.second)-compress.begin();
		if (query[i].second==0){
			point[x].insert(y);
			update(1, 0, MAXN-1, x, *point[x].rbegin());
		}
		else if (query[i].second==1){
			point[x].erase(y);
			update(1, 0, MAXN-1, x, *point[x].rbegin());
		}
		else{
			pii ans=BS(1, 0, MAXN-1, x+1, MAXN-1, {y+1, -1});
			if (ans==make_pair(-1, -1)) cout<<"-1\n";
			else{
				int X=ans.second, Y=*(point[X].upper_bound(y));
				cout<<compress[X]<<' '<<compress[Y]<<'\n';
			}
		}
	}
	
	
	return 0;
}