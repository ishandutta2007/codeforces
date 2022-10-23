#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,h[300005],b[300005],pos[300005],L[300005],R[300005];
int f[300005][20],B[300005];
ll l[300005],r[300005],s[300005],g[300005];
set<int> S;
int get(int l,int r){
	if(l>r) return 0;
	int d=B[r-l];
	int x=f[l][d],y=f[r-(1<<d)+1][d];
	if(h[x]<h[y]) return x;
	return y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",h+i),pos[h[i]]=i;
	for(int i=1;i<=n;++i)scanf("%d",b+i);
	S.insert(0);
	S.insert(n+1);
	for(int i=1;i<=n;++i){
		set<int>::iterator it=S.lower_bound(pos[i]);
		R[i]=*it-1;
		--it;
		L[i]=*it+1;
		S.insert(pos[i]);
	}
	for(int i=1;i<=n;++i){
		B[i]=B[i-1];
		if(i==(2<<B[i]))++B[i];
	}
	for(int i=1;i<=n;++i)f[i][0]=i;
	for(int k=0;k<18;++k){
		for(int i=1;i<=n-(1<<k)+1;++i)f[i][k+1]=(h[f[i][k]]<h[f[i+(1<<k)][k]])?f[i][k]:f[i+(1<<k)][k];
	}
	for(int i=n;i;--i){
		int lc=h[get(L[i],pos[i]-1)],rc=h[get(pos[i]+1,R[i])];
		s[i]=l[lc]+b[pos[i]]+r[rc];
		l[i]=max(l[lc],l[lc]+b[pos[i]]+g[rc]);
		r[i]=max(r[rc],r[rc]+b[pos[i]]+g[lc]);
		g[i]=max(max(g[lc],g[rc]),b[pos[i]]+g[lc]+g[rc]);
	}
	printf("%I64d\n",s[1]);
    return 0;
}