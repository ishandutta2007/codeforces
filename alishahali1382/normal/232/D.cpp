#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops,no-stack-protector,fast-math")

using namespace std;

const int inf=1000000010;
const int MAXN=200010, LOG=19;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int Rank[MAXN][LOG], P[MAXN], PR[MAXN], pw, N;
int Lcp[MAXN][LOG];
int root[MAXN];
int seg[LOG*MAXN], L[MAXN*LOG], R[MAXN*LOG], ts;

bool cmp(int x, int y){
	if (Rank[x][pw-1]!=Rank[y][pw-1]) return Rank[x][pw-1]<Rank[y][pw-1];
	if (max(x, y)+(1<<(pw-1))>N) return x>y;
	return Rank[x+(1<<(pw-1))][pw-1]<Rank[y+(1<<(pw-1))][pw-1];
}

void BuildSuffixArray(){
	for (int i=1; i<=N; i++) Rank[i][0]=A[i], P[i]=i;
	for (pw=1; pw<LOG; pw++){
		sort(P+1, P+N+1, cmp);
		Rank[P[1]][pw]=1;
		for (int i=2; i<=N; i++) Rank[P[i]][pw]=Rank[P[i-1]][pw]+cmp(P[i-1], P[i]);
	}
}

int Add(int id, int tl, int tr, int pos){
	if (pos<tl || tr<=pos) return id;
	int res=++ts;
	if (tr-tl==1) seg[res]=1;
	else{
		int mid=(tl+tr)>>1;
		L[res]=Add(L[id], tl, mid, pos);
		R[res]=Add(R[id], mid, tr, pos);
		seg[res]=seg[L[res]]+seg[R[res]];
	}
	return res;
}

int Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return Get(L[id], tl, mid, l, r) + Get(R[id], mid, tr, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++) A[i]-=A[i+1];
	for (int i=1; i<n; i++) A[i+n]=-A[i];
	A[n]=inf;
	N=2*n-1;
	
	BuildSuffixArray();
	for (int i=1; i<=N; i++) PR[P[i]]=i;
	for (int i=1; i+1<=N; i++){
		int x=P[i], y=P[i+1];
		if (x<y) swap(x, y);
		for (int j=LOG-1; ~j && x<=N; j--) if (Rank[x][j]==Rank[y][j]){
			Lcp[i][0]|=(1<<j);
			x+=(1<<j);
			y+=(1<<j);
		}
	}
	for (int j=1; j<LOG; j++)
		for (int i=1; i+(1<<j)<=N+1; i++)
			Lcp[i][j]=min(Lcp[i][j-1], Lcp[i+(1<<(j-1))][j-1]);
	
	for (int i=1; i<=N; i++) root[i]=Add(root[i-1], 1, N+1, PR[i]);
	cin>>m;
	while (m--){
		cin>>x>>y;
		if (x==y){
			cout<<n-1<<'\n';
			continue ;
		}
		y-=x;
		x+=n;
		int l=PR[x], r=PR[x];
		for (int i=LOG-1; ~i; i--) if (l-(1<<i)>0 && Lcp[l-(1<<i)][i]>=y) l-=(1<<i);
		for (int i=LOG-1; ~i; i--) if (r+(1<<i)<=N && Lcp[r][i]>=y) r+=(1<<i);
		r++;
		x-=n;
		ans=0;
		if (0<x-y+1) ans+=Get(root[x-y-1], 1, N+1, l, r);
		ans+=Get(root[n], 1, N+1, l, r);
		ans-=Get(root[x+y], 1, N+1, l, r);
		cout<<ans<<'\n';
	}
	
	return 0;
}