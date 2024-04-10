#include<bits/stdc++.h>
#define M 200100
#define N 1010
using namespace std;
struct qry{
	int s,t,l,r,id;
	bool operator<(const qry& rhs)const{return l>rhs.l;}
}qs[M];
int ans[M],a[M],b[M],last[N][N];
const int inf=0x3f3f3f3f;
int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	memset(last,0x3f,sizeof(last));
	for(int i=1;i<=n;i++) last[i][i]=0;
	for(int i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=0;i<q;i++){
		scanf("%d%d%d%d",&qs[i].l,&qs[i].r,&qs[i].s,&qs[i].t);
		qs[i].id=i;
	}
	sort(qs,qs+q);
	int now=0;
	for(int i=m;i>=1;i--){
		last[a[i]][b[i]]=last[b[i]][a[i]]=i;
		for(int j=1;j<=n;j++){
			if(j!=a[i]&&j!=b[i])last[a[i]][j]=last[b[i]][j]=min(last[a[i]][j],last[b[i]][j]);
		}
		while(now<q&&qs[now].l==i){
			if(qs[now].r>=last[qs[now].s][qs[now].t]) ans[qs[now].id]=1;
			now++;
		}
	}
	for(int i=0;i<q;i++){
		if(ans[i]) puts("Yes");
		else puts("No");
	}
	return 0;
}