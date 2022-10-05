#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
char s[N];
int q[N],l;
struct AC{
	struct T{
		int c[27],d[27],f,s,t;
	}t[N];
	int rt[23],sz[23],id,tp;
	void mg(int&x,int y){
		if(!x||!y)return void(x+=y);
		t[x].t+=t[y].t;
		for(int i=0;i<26;++i)mg(t[x].c[i],t[y].c[i]);
	}
	void bfs(int x){
		int u=0,v=0,i,j,k;
		for(i=0;i<26;++i)
			if(t[x].c[i])t[q[++v]=t[x].d[i]=t[x].c[i]].f=x;
			else t[x].d[i]=x;
		while(u!=v){
			i=q[++u],k=t[i].f;
			for(j=0;j<26;++j)
				if(t[i].c[j])t[q[++v]=t[i].d[j]=t[i].c[j]].f=t[k].d[j];
				else t[i].d[j]=t[k].d[j];
			t[i].s=t[i].t+t[t[i].f].s;
		}
	}
	void ins(){
		int i,x,y;
		x=rt[++tp]=++id,sz[tp]=1;
		for(i=0;i<l;++i){
			y=s[i]-'a';
			if(!t[x].c[y])t[x].c[y]=++id;
			x=t[x].c[y];
		}
		t[x].t=1;
		while(sz[tp-1]==sz[tp])mg(rt[tp-1],rt[tp]),sz[--tp]<<=1;
		bfs(rt[tp]);
	}
	long long qry(){
		long long ans=0;
		int i,j,x;
		for(i=tp;i;--i)
			for(j=0,x=rt[i];j<l;++j)x=t[x].d[s[j]-'a'],ans+=t[x].s;
		return ans;
	}
}A,B;
int main(){
	int m,x;
	scanf("%d",&m);
	while(m--){
		scanf("%d%s",&x,s),l=strlen(s);
		if(x==1)A.ins();
		else if(x==2)B.ins();
		else printf("%lld\n",A.qry()-B.qry()),fflush(stdout);
	}
	return 0;
}