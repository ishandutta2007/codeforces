#include<bits/stdc++.h>
using namespace std;
const int B=15e4+1,N=3e5+7;
vector<int>g[N],v[N];
int l[N],id,st[N],tp,bl[N],ct,c[N],t[N],o,m,a[N];
void ins(int x,int y){g[x].push_back(y),g[y>B?y-B:y+B].push_back(x>B?x-B:x+B);}
void tar(int x){
	int p=++id;
	l[st[++tp]=x]=p;
	for(int i:g[x])if(!l[i])tar(i),l[x]=min(l[x],l[i]);else if(!bl[i])l[x]=min(l[x],l[i]);
	if(l[x]==p)for(++ct;bl[st[tp]]=ct,st[tp--]!=x;);
}
bool chk(int x){
	int i;
	memset(l,0,N*4),memset(bl,0,N*4),id=ct=0;
	for(i=1;i<=m;++i)if(t[i]>x)g[i].push_back(i+B);
	for(i=1;i<=o;++i){
		if(!l[i])tar(i);
		if(!l[i+B])tar(i+B);
	}
	for(i=1;i<=m;++i)if(t[i]>x)g[i].pop_back();
	for(i=1;i<=o;++i)if(bl[i]==bl[i+B])return 0;
	return 1;
}
int main(){
	int n,i,j,k,l=0,r=1e9;
	scanf("%d%d",&n,&m),o=m;
	for(i=1;i<=m;++i){
		scanf("%d%d%d%d",&j,&k,c+i,t+i);
		v[j].push_back(i),v[k].push_back(i);
	}
	for(i=1;i<=n;++i){
		k=0;
		for(int z:v[i])a[++k]=z;
		sort(a+1,a+k+1,[](int x,int y){return c[x]<c[y];}),a[k+1]=0;
		for(j=1;j<=k;++j){
			if(j>1)ins(a[j],o+B),ins(o,o+1);
			ins(a[j],++o);
			if(c[a[j]]==c[a[j-1]]){
				if(c[a[j]]==c[a[j+1]])return puts("No"),0;
				ins(a[j-1]+B,a[j]);
			}
		}
	}
	if(!chk(r))return puts("No"),0;
	while(l<=r){
		k=l+r>>1;
		if(chk(k))r=k-1;else l=k+1;
	}
	chk(++r),printf("Yes\n%d ",r);
	for(i=1;i<=m;++i)if(bl[i]<bl[i+B])st[++tp]=i;
	printf("%d\n",tp);
	for(i=1;i<=tp;++i)printf("%d ",st[i]);
	return 0;
}