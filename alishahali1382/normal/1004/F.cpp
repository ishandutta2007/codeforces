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
const int MAXN = 100010, LOG=20;

struct node{
	ll ans=0;
	vector<pii> pref, suff;
} seg[MAXN<<2];

int n, m, k, u, v, x, y, t, X;
int A[MAXN];

node combine(node x, node y){
	if (x.pref.empty()) return y;
	if (y.pref.empty()) return x;
	node out;
	out.ans=x.ans+y.ans;
	for (pii p:x.suff) for (pii pp:y.pref) if ((p.first|pp.first)>=X) out.ans+=1ll*p.second*pp.second;
	
	out.pref=x.pref;
	for (pii p:y.pref){
		if (out.pref.empty() || (out.pref.back().first&p.first)!=p.first) out.pref.pb({p.first|out.pref.back().first, p.second});
		else out.pref[out.pref.size()-1].second+=p.second;
	}
	
	out.suff=y.suff;
	for (pii p:x.suff){
		if (out.suff.empty() || (out.suff.back().first&p.first)!=p.first) out.suff.pb({p.first|out.suff.back().first, p.second});
		else out.suff[out.suff.size()-1].second+=p.second;
	}
	return out;
}

node build(int id, int tl, int tr){
	//cerr<<"build "<<id<<' '<<tl<<' '<<tr<<'\n';
	if (tr-tl==1){
		seg[id].pref.pb({A[tl], 1});
		seg[id].suff.pb({A[tl], 1});
		seg[id].ans=(A[tl]>=X);
		return seg[id];
	}
	int mid=(tl+tr)>>1;
	return seg[id]=combine(build(id<<1, tl, mid), build(id<<1 | 1, mid, tr));
}

void update(int id, int tl, int tr, int pos){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id].pref=seg[id].suff={{A[tl], 1}};
		seg[id].ans=(A[tl]>=X);
		return ;
	}
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, pos);
	update(id<<1 | 1, mid, tr, pos);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

node get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return combine(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid, tr, l, r));
}

void print(node x){
	cerr<<'\n';
	cerr<<x.ans<<'\n';
	cerr<<"pref:\n";
	for (pii p:x.pref) debugp(p)
	cerr<<"suff:\n";
	for (pii p:x.suff) debugp(p)
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>X;
	for (int i=1; i<=n; i++) cin>>A[i];
	build(1, 1, n+1);
	/*
	for (int i=1; i<=7; i++){
		cerr<<"\n"<<i<<" : \n";
		for (pii p:seg[i].pref) debugp(p)
	}
	debug(seg[1].ans)
	cerr<<'\n';
	cerr<<"seg[2] : ";
	print(seg[2]);
	cerr<<'\n';
	cerr<<"seg[3] : ";
	print(seg[3]);
	*/
	
	
	while (m--){
		cin>>t>>x>>y;
		if (t==2) cout<<get(1, 1, n+1, x, y+1).ans<<'\n';
		else{
			A[x]=y;
			update(1, 1, n+1, x);
			continue ;
		}
	}
	
	return 0;
}
/*
5 1 7
6 0 3 15 2
2 1 5



*/