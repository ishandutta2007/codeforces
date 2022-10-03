#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int seg[MAXN<<2], lazy[MAXN<<2];
vector<int> vec[MAXN];

void add_lazy(int id, int val){
	seg[id]+=val;
	lazy[id]+=val;
}
void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}
void Add(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
}

void Solve(){
	memset(seg, 0, sizeof(seg));
	memset(lazy, 0, sizeof(lazy));
	cin>>n>>m;
	while (n--){
		cin>>x;
		Add(1, 1, MAXN, 1, x+1, -1);
	}
	for (int i=0; i<m; i++){
		cin>>x;
		vec[i].resize(x);
		ll sum=0;
		for (int j=0; j<x; j++) cin>>vec[i][j], sum+=vec[i][j];
		int y=(sum-1)/x+1;
		Add(1, 1, MAXN, 1, y+1, +1);
	}
	string out;
//	debug(SZ(vec[0]))
//	debug(SZ(vec[1]))
	
	for (int i=0; i<m; i++){
		x=SZ(vec[i]);
		ll sum=0;
		for (int j=0; j<x; j++) sum+=vec[i][j];
		int y=(sum-1)/x+1;
		Add(1, 1, MAXN, 1, y+1, -1);
		for (int j=0; j<x; j++){
			sum-=vec[i][j];
			int yy=(sum-1)/(x-1)+1;
			Add(1, 1, MAXN, 1, yy+1, +1);
			out+='0'+(seg[1]<=0);
			Add(1, 1, MAXN, 1, yy+1, -1);
			sum+=vec[i][j];
		}
		Add(1, 1, MAXN, 1, y+1, +1);
//		debug2(SZ(vec[i]), SZ(out))
	}
	cout<<out<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}