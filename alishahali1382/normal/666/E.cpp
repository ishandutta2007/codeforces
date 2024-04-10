#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops,no-stack-protector,fast-math")

using namespace std;
typedef pair<int, int> pii;
#define pb push_back

const int MAXN=600010, LOG=20;

int n, m, k, u, v, x, y, t, l, r;
int A[MAXN], ID[MAXN], N;
int Rank[LOG][MAXN], P[MAXN], pw;
int koj[MAXN], P2[MAXN], P3[MAXN], M;
int Lcp[LOG][MAXN], LG[MAXN];
int L[MAXN], R[MAXN], PL[MAXN], PR[MAXN];
pii seg[MAXN<<1], ans[MAXN];
int cnt[MAXN];
string S, T[MAXN];
map<pii, vector<int>> Q;

bool cmp(int x, int y){
	if (Rank[pw][x]!=Rank[pw][y]) return Rank[pw][x]<Rank[pw][y];
	if (max(x, y)+(1<<pw)>=N) return x>y;
	return Rank[pw][x+(1<<pw)]<Rank[pw][y+(1<<pw)];
}

void BuildSuffixArray(){
	for (int i=0; i<N; i++) Rank[0][i]=A[i], P[i]=i;
	for (; pw+1<LOG; pw++){
		sort(P, P+N, cmp);
		for (int i=1; i<N; i++) Rank[pw+1][P[i]]=Rank[pw+1][P[i-1]]+cmp(P[i-1], P[i]);
	}
}

void BuildLcp(){
	for (int i=0; i+1<N; i++){
		int res=0, x=P[i], y=P[i+1];
		if (x<y) swap(x, y);
		for (int j=LOG-1; ~j && x<N; j--) if (Rank[j][x]==Rank[j][y]){
			res|=(1<<j);
			x+=(1<<j);
			y+=(1<<j);
		}
		Lcp[0][i]=res;
	}
	for (int j=1; j<LOG; j++) for (int i=0; i+(1<<j)<N; i++)
		Lcp[j][i]=min(Lcp[j-1][i], Lcp[j-1][i+(1<<(j-1))]);
}

int GetLcp(int x, int y){
	x=koj[x];
	y=koj[y];
	if (x>y) swap(x, y);
	int lg=LG[y-x];
	return min(Lcp[lg][x], Lcp[lg][y-(1<<lg)]);
}

void Set(int pos, pii val){
	for (seg[pos+=n+1]=val; pos>1; pos>>=1) seg[pos>>1]=max(seg[pos], seg[pos^1]);
}
pii Get(int l, int r){
	pii res={-1, -1};
	for (l+=n+1, r+=n+1; l<r; l>>=1, r>>=1){
		if (l&1) res=max(res, seg[l++]);
		if (r&1) res=max(res, seg[--r]);
	}
	return res;
}

inline void add(int x){ x=P3[x]; Set(x, {++cnt[x], -x});}
inline void rem(int x){ x=P3[x]; Set(x, {--cnt[x], -x});}
inline void Solve(int id){
	pii p=Get(PL[id], PR[id]+1);
	p.second*=-1;
	if (p.first==0) p.second=PL[id];
	ans[id]=p;	
}

void dfs(int tl, int tr){ // [tl, tr]
	if (tl>tr) return ;
	if (tl==tr){
		add(tl);
		for (int id:Q[{tl, tr}]) Solve(id);
		return ;
	}
	vector<pii> vec;
	int lcp=GetLcp(P2[tl], P2[tr]);
	int last=tl;
	while (A[P2[last]+lcp]!=A[P2[tr]+lcp]){
		int dwn=last, up=tr;
		while (up-dwn>1){
			int mid=(dwn+up)>>1;
			if (A[P2[last]+lcp]==A[P2[mid]+lcp]) dwn=mid;
			else up=mid;
		}
		vec.pb({last, dwn});
		last=up;
	}
	vec.pb({last, tr});
	pii big={0, -1};
	for (pii p:vec) if (p.second-p.first>big.second-big.first) big=p;
	for (pii p:vec) if (p!=big){
		dfs(p.first, p.second);
		for (int i=p.first; i<=p.second; i++) rem(i);
	}
	dfs(big.first, big.second);
	for (pii p:vec) if (p!=big){
		for (int i=p.first; i<=p.second; i++) add(i);
	}
	for (int id:Q[{tl, tr}]) Solve(id);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<MAXN; i++) LG[i]=LG[i>>1]+1;
	cin>>S>>n;
	for (char ch:S) A[N++]=ch;
	for (int i=1; i<=n; i++){
		A[N++]=-i;
		cin>>T[i];
		for (char ch:T[i]) ID[N]=i, A[N++]=ch;
	}
	
	BuildSuffixArray();
	BuildLcp();
	for (int i=0; i<N; i++){
		koj[P[i]]=i;
		if (ID[P[i]]) P2[M++]=i;
	}
	
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>PL[i]>>PR[i]>>x>>y;
		y=y-x+1;
		x=koj[x-1];
		l=r=x;
		for (int j=LOG-1; ~j; j--) if (l-(1<<j)>=0 && Lcp[j][l-(1<<j)]>=y) l-=(1<<j);
		for (int j=LOG-1; ~j; j--) if (Lcp[j][r]>=y) r+=(1<<j);
		
		L[i]=lower_bound(P2, P2+M, l)-P2;
		R[i]=upper_bound(P2, P2+M, r)-P2;
		if (L[i]<R[i]) Q[{L[i], R[i]-1}].pb(i);
		else ans[i]={0, PL[i]};
	}
	for (int i=0; i<M; i++) P3[i]=ID[P2[i]=P[P2[i]]];
	dfs(0, M-1);
	for (int i=1; i<=m; i++) cout<<ans[i].second<<' '<<ans[i].first<<'\n';
	
	return 0;
}