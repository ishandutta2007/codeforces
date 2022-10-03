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

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=500010, LOG=19;

int n, m, k, u, v, x, y, t, a, b;
int S[MAXN], ID[MAXN], ps[MAXN], N;
int L[MAXN], R[MAXN], R2[MAXN];
int Rank[LOG][MAXN], P[MAXN];
int cnt[MAXN], P2[MAXN];
pii ans[MAXN];
int seg[MAXN<<2];
string X[MAXN];
vector<int> Q[MAXN];

inline bool cmp(int x, int y, int pw){
	if (Rank[pw][x]!=Rank[pw][y]) return Rank[pw][x]<Rank[pw][y];
	if (max(x, y)+(1<<pw)>=N) return x>y;
	return Rank[pw][x+(1<<pw)]<Rank[pw][y+(1<<pw)];
}
void BuildSuffixArray(){
	for (int i=0; i<N; i++) P[i]=i;
	sort(P, P+N, [](int i, int j){ return S[i]<S[j];});
	for (int i=1; i<N; i++) Rank[0][P[i]]=Rank[0][P[i-1]]+(S[P[i-1]]<S[P[i]]);
	for (int j=0; j+1<LOG; j++){
		int x=0;
		for (int i=0; i<N; i++) if (P[i]+(1<<j)>=N) P2[x++]=P[i];
		for (int i=0; i<N; i++) if ((1<<j)<=P[i]) P2[x++]=P[i]-(1<<j);
		for (int i=0; i<N; i++) cnt[i]=0;
		for (int i=0; i<N; i++) cnt[Rank[j][i]]++;
		for (int i=1; i<N; i++) cnt[i]+=cnt[i-1];
		for (int i=N-1; ~i; i--) P[--cnt[Rank[j][P2[i]]]]=P2[i];
		for (int i=1; i<N; i++) Rank[j+1][P[i]]=Rank[j+1][P[i-1]]+cmp(P[i-1], P[i], j);
	}
}
int GetLcp(int x, int y){
	if (x>y) swap(x, y);
	int res=0;
	for (int i=LOG-1; ~i && y<N; i--) if (Rank[i][x]==Rank[i][y]) x+=(1<<i), y+=(1<<i), res|=(1<<i);
	return res;
}
inline bool CMP(pii p1, pii p2){ // [...)  [...)
	int lcp=GetLcp(p1.first, p2.first);
//	debug(lcp)
	int s1=p1.second-p1.first, s2=p2.second-p2.first;
	if (lcp>=s2) return 0;
	if (lcp>=s1) return 1;
	return S[p1.first+lcp]<S[p2.first+lcp];
}
void Set(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id]=val;
		return ;
	}
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, pos, val);
	Set(id<<1 | 1, mid, tr, pos, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}
int BS(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l || val<=seg[id]) return -1;
	if (tr-tl==1) return seg[id];
	int mid=(tl+tr)>>1;
	int res=BS(id<<1, tl, mid, l, r, val);
	if (res!=-1) return res;
	return BS(id<<1 | 1, mid, tr, l, r, val);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>X[0]>>m;
	n=X[0].size();
	for (char c:X[0]) S[N++]=c-'a';
	for (int i=1; i<=m; i++){
		cin>>L[i]>>R[i]>>X[i];
		ps[i]=ps[i-1]+SZ(X[i-1])+1;
		S[N]=-i, ID[N++]=-1;
		for (char c:X[i]) S[N]=c-'a', ID[N++]=i;
	}
	S[N]=-m-1, ID[N++]=-1;
	
	BuildSuffixArray();
//	cerr<<"P: ";for (int i=0; i<N; i++) cerr<<P[i]<<" \n"[i==N-1];
	
	for (int i=1; i<=m; i++){
		ans[i]={-1, -1};
		int l=--L[i], r=R[i], sz=SZ(X[i]);
		for (int j=max(l, r-sz); j<r; j++) if (CMP({ps[i], ps[i]+sz}, {j, r})){
			if (ans[i].first==-1 || CMP({j, r}, ans[i])) ans[i]={j, r};
		}
		if (l<r-sz){
			R2[i]=R[i]-sz;
			Q[L[i]].pb(i);
		}
	}
	memset(seg, 63, sizeof(seg));
	for (int l=n-1; ~l; l--){
		Set(1, 0, N, Rank[LOG-1][l], l);
		for (int i:Q[l]){
			int sz=SZ(X[i]);
			int dwn=-1, up=N;
			while (up-dwn>1){
				int mid=(dwn+up)>>1;
				if (CMP({ps[i], ps[i]+sz+1}, {P[mid], P[mid]+sz+1})) up=mid;
				else dwn=mid;
			}
			int pos=BS(1, 0, N, up, N, R2[i]);
			if (pos==-1) continue ;
			pii p={pos, R[i]};
			if (ans[i].first==-1 || CMP(p, ans[i])) ans[i]=p;
		}
	}
	
	for (int i=1; i<=m; i++){
		if (ans[i].first==-1) cout<<"-1\n";
		else{
			int j=ans[i].first, k=0;
			while (1){
				cout<<X[0][j];
				if (X[0][j]!=X[i][k]) break ;
				else j++, k++;
			}
			cout<<"\n";
		}
	}
	
	return 0;
}
/*
cacbd
1
1 4 c

cacbdaa
1
1 4 c

*/