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
const int MAXN = 100010, LOG=20, M=1e9+9, B=10007, Z=0-'0';

int n, m, k, u, v, x, y, t, l, r, ans;
ll tav[MAXN], tmp[MAXN];
ll seg[MAXN<<2];
int lazy[MAXN<<2];

void build(int id, int tl, int tr){
	if (tr-tl==1){
		char ch;cin>>ch;
		seg[id]=ch+Z;
		return ;
	}
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid, tr);
	seg[id]=(tav[tr-mid]*seg[id<<1] + seg[id<<1 | 1])%M;
	//cerr<<tl<<' '<<tr<<"   "<<seg[id]<<'\n';
}

void add_lazy(int id, int len, int lz){
	seg[id]=tmp[len]*lz;
	lazy[id]=lz;
}

void shift(int id, int tl, int tr){
	if (lazy[id]==-1) return ;
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, mid-tl, lazy[id]);
	add_lazy(id<<1 | 1, tr-mid, lazy[id]);
	lazy[id]=-1; 
}

void Set(int id, int tl, int tr, int l, int r, int lz){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, tr-tl, lz);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, l, r, lz);
	Set(id<<1 | 1, mid, tr, l, r, lz);
	seg[id]=(tav[tr-mid]*seg[id<<1] + seg[id<<1 | 1])%M;
}

pair<ll, int> Hash(int id, int tl, int tr, int l, int r){
	if (tr<=l || r<=tl) return {0, 0};
	if (l<=tl && tr<=r) return {seg[id], tr-tl};
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	auto hl=Hash(id<<1, tl, mid, l, r);
	auto hr=Hash(id<<1 | 1, mid, tr, l, r);
	return {(tav[hr.second]*hl.first + hr.first)%M, hl.second+hr.second};
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tmp[i]=(tmp[i-1]*B+1)%M, tav[i]=tav[i-1]*B%M;
	cin>>n>>m>>k;
	m+=k;
	memset(lazy, -1, sizeof(lazy));
	build(1, 1, n+1);
	while (m--){
		cin>>t>>l>>r>>k;
		if (t==1) Set(1, 1, n+1, l, r+1, k);
		else{
			auto h1=Hash(1, 1, n+1, l, r-k+1);
			auto h2=Hash(1, 1, n+1, l+k, r+1);
			//debugp(h1)
			//debugp(h2)
			if (h1==h2) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	
	return 0;
}
/*
6 0 2
334934
1 4 4 3
2 1 6 3

6 0 2
334934
1 4 4 3
2 1 6 3

6 2 3
334934
2 2 5 2
1 4 4 3
2 1 6 3
1 2 3 8
2 3 6 1



*/