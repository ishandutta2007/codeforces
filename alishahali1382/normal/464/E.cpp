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
const int mod = 1000000007, M=1e9+7, B=2, Z=360;
const int MAXN = 100030;

int n, m, k, u, v, x, y, s, t, N=1;
ll tav[MAXN];
int L[MAXN*Z], R[MAXN*Z];
int C[MAXN*Z], H[MAXN*Z];
int root[MAXN], par[MAXN];
bool mark[MAXN], mark2[MAXN];
vector<pii> G[MAXN];

int Cmp(int r1, int r2, int tl=0, int tr=MAXN){
	if (tr-tl==1) return C[r1]-C[r2];
	int mid=(tl+tr)>>1;
	if (H[R[r1]]==H[R[r2]]) return Cmp(L[r1], L[r2], tl, mid);
	return Cmp(R[r1], R[r2], mid, tr);
}

int Set0(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return id;
	if (l<=tl && tr<=r) return 0;
	int res=N++, mid=(tl+tr)>>1;
	L[res]=Set0(L[id], tl, mid, l, r);
	R[res]=Set0(R[id], mid, tr, l, r);
	C[res]=C[L[res]]+C[R[res]];
	H[res]=(H[L[res]]+H[R[res]]*tav[mid-tl])%M;
	return res;
}

int Set1(int id, int tl, int tr, int pos){
	if (tr<=pos || pos<tl) return id;
	if (tr-tl==1){
		int res=N++;
		H[res]=C[res]=1;
		return res;
	}
	int res=N++, mid=(tl+tr)>>1;
	L[res]=Set1(L[id], tl, mid, pos);
	R[res]=Set1(R[id], mid, tr, pos);
	C[res]=C[L[res]]+C[R[res]];
	H[res]=(H[L[res]]+H[R[res]]*tav[mid-tl])%M;
	return res;
}

int Find(int id, int tl, int tr, int pos){
	//cerr<<"Find "<<id<<' '<<tl<<' '<<tr<<"  "<<pos<<'\n';
	//debug(C[id])
	//if (k++==30) exit(0);
	if (tr<=pos) return -1;
	if (pos<=tl){
		if (C[id]==tr-tl) return -1;
		if (!C[id]) return tl;
	}
	int mid=(tl+tr)>>1;
	int tmp=Find(L[id], tl, mid, pos);
	if (tmp==-1) tmp=Find(R[id], mid, tr, pos);
	return tmp;
}

int Add(int id, int bit){
	int tmp=Find(id, 0, MAXN, bit);
	id=Set0(id, 0, MAXN, bit, tmp);
	id=Set1(id, 0, MAXN, tmp);
	return id;
}

struct CMP{
	bool operator ()(int u, int v){
		int tmp=Cmp(root[u], root[v]);
		if (!tmp) return u<v;
		return tmp<0;
	}
};
set<int, CMP> st;
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*B%mod;
	
	cin>>n>>m;
	while (m--){
		cin>>u>>v>>x;
		G[u].pb({v, x});
		G[v].pb({u, x});
	}
	cin>>s>>t;
	
	st.insert(s);
	while (!st.empty()){
		auto it=st.begin();
		int v=*it;
		st.erase(it);
		//debug(v)
		if (mark[v]) continue ;
		mark[v]=1;
		for (pii p:G[v]) if (!mark[p.first]){
			int tmp=Add(root[v], p.second);
			if (!mark2[p.first] || Cmp(tmp, root[p.first])<0){
				st.erase(p.first);
				root[p.first]=tmp;
				st.insert(p.first);
				mark2[p.first]=1;
				par[p.first]=v;
			}
		}
	}
	if (!mark[t]) kill(-1)
	cout<<H[root[t]]<<'\n';
	vector<int> path;
	for (int v=t; v; v=par[v]) path.pb(v);
	reverse(all(path));
	cout<<path.size()<<'\n';
	for (int v:path) cout<<v<<' ';
	
	return 0;
}