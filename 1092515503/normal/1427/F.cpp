#include<bits/stdc++.h>
using namespace std;
int n,m,stk[1210],tp;
char s[410][40];
int fa[410],deg[410],L[410],R[410];
bool col[1210],c[410],era[410];
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n*3;i++)scanf("%d",&x),col[x]=true;
	for(int i=1;i<=n*6;i++){
		stk[++tp]=i;
		if(tp>=3&&col[stk[tp-2]]==col[stk[tp-1]]&&col[stk[tp-1]]==col[stk[tp]])
			++m,L[m]=stk[tp-2],R[m]=stk[tp],c[m]=!col[i],
			sprintf(s[m],"%d %d %d\n",stk[tp-2],stk[tp-1],stk[tp]),tp-=3;
	}
//	for(int i=1;i<=m;i++)printf("[%d,%d]\n",L[i],R[i]);
	for(int i=1;i<=m;i++){
		while(tp&&L[i]<=L[stk[tp]]&&R[stk[tp]]<=R[i])fa[stk[tp--]]=i,deg[i]++;
		stk[++tp]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(!c[j]&&!deg[j]&&!era[j])
			{printf("%s",s[j]),era[j]=true,deg[fa[j]]--;break;}
		bool pr=false;
		for(int j=1;j<=m;j++)if(c[j]&&!deg[j]&&!era[j]&&fa[j])
			{printf("%s",s[j]),era[j]=true,deg[fa[j]]--,pr=true;break;}
		if(pr)continue;
		for(int j=1;j<=m;j++)if(c[j]&&!deg[j]&&!era[j])
			{printf("%s",s[j]),era[j]=true,deg[fa[j]]--,pr=true;break;}
	}
	return 0;
}