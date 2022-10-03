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
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, q, u, v, x, y, t, a, b, ans;
int L[MAXN], R[MAXN], par[MAXN];
int typ[MAXN], A[MAXN], B[MAXN];
vector<int> comp;

int getpar(int x){
	if (par[x]==x) return x;
	return par[x]=getpar(par[x]);
}
void join(int x, int y){
//	debug2(x, y)
	x=getpar(x);
	y=getpar(y);
	if (x==y) return ;
	L[x]=min(L[x], L[y]);
	R[x]=max(R[x], R[y]);
	par[y]=x;
}

struct SEGMENT1{
	set<pii> st[MAXN];
	pii seg[MAXN<<1];
	SEGMENT1(){
		memset(seg, 63, sizeof(seg));
	}
	void relax(int pos){
		seg[pos+MAXN]=(st[pos].empty()?pii(inf, inf):(*st[pos].begin()));
		for (pos+=MAXN; pos>1; pos>>=1) seg[pos>>1]=min(seg[pos], seg[pos^1]);
	}
	pii Get(int l, int r){
		pii res={inf, -1};
		for (l+=MAXN, r+=MAXN; l<r; l>>=1, r>>=1){
			if (l&1) res=min(res, seg[l++]);
			if (r&1) res=min(res, seg[--r]);
		}
		return res;
	}
	void add(int l, int r, int id){
		st[r].insert({l, id});
		relax(r);
	}
	void rem(int l, int r, int id){
		st[r].erase({l, id});
		relax(r);
	}
} seg1;
struct SEGMENT2{
	set<pii> st[MAXN];
	pii seg[MAXN<<1];
	SEGMENT2(){
		memset(seg, -63, sizeof(seg));
	}
	void relax(int pos){
		seg[pos+MAXN]=(st[pos].empty()?pii(inf, -inf):(*st[pos].begin()));
		seg[pos+=MAXN].first*=-1;
		for (; pos>1; pos>>=1) seg[pos>>1]=max(seg[pos], seg[pos^1]);
	}
	pii Get(int l, int r){
		pii res={-inf, -1};
		for (l+=MAXN, r+=MAXN; l<r; l>>=1, r>>=1){
			if (l&1) res=max(res, seg[l++]);
			if (r&1) res=max(res, seg[--r]);
		}
		return res;
	}
	void add(int l, int r, int id){
		st[l].insert({-r, id});
		relax(l);
	}
	void rem(int l, int r, int id){
		st[l].erase({-r, id});
		relax(l);
	}
} seg2;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>q;
	for (int i=1; i<=q; i++){
		cin>>typ[i]>>A[i]>>B[i];
		if (typ[i]==1){
			comp.pb(A[i]);
			comp.pb(B[i]);
		}
	}
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	m=comp.size();
	for (int i=1; i<=q; i++){
		if (typ[i]==2){
			x=getpar(A[i]);
			y=getpar(B[i]);
			if (x==y || (L[y]<=L[x] && R[x]<=R[y])) cout<<"YES\n";
			else cout<<"NO\n";
			continue ;
		}
		n++;
		par[n]=n;
		L[n]=A[i]=lower_bound(all(comp), A[i])-comp.begin();
		R[n]=B[i]=lower_bound(all(comp), B[i])-comp.begin();
		while (1){
			int id=seg1.Get(B[i]+1, m).second;
			if (id<0 || id>n || B[i]<=L[id]) break ;
			seg1.rem(L[id], R[id], id);
			seg2.rem(L[id], R[id], id);
			join(n, id);
		}
		while (1){
			int id=seg2.Get(0, A[i]).second;
			if (id<0 || id>n || R[id]<=A[i]) break ;
			seg1.rem(L[id], R[id], id);
			seg2.rem(L[id], R[id], id);
			join(n, id);
		}
		seg1.add(L[n], R[n], n);
		seg2.add(L[n], R[n], n);
	}
	
	return 0;
}
/*
5
1 1 5
1 5 11
2 1 2
1 2 9
2 1 2

*/