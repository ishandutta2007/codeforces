#include<bits/stdc++.h>
using namespace std;
const int BBB=500;
int n,m,a[100100],BLK[100100],go[100100],len[100100],dep[100100],lp[510],tag[510],num;
bool fin[510];
void rebuild(int id,int L,int R,int x){
	if(L<=lp[id]&&R>=lp[id+1]-1&&fin[id]){tag[id]+=x,tag[id]=min(tag[id],n);return;}
	fin[id]=true;
	for(int i=lp[id];i<lp[id+1];i++){
		a[i]=max(0,a[i]-tag[id]);
		if(L<=i&&i<=R)a[i]=max(0,a[i]-x);
		if(a[i]<lp[id])go[i]=i,len[i]=0;else go[i]=go[a[i]],len[i]=len[a[i]]+1,fin[id]=false;
	}
	tag[id]=0;
}
#define fa(x) max(a[x]-tag[BLK[x]],0)
int chain(int x){
	if(x==0)return dep[x]=0;
	dep[go[x]]=chain(fa(go[x]))+1;
	if(!go[x])dep[go[x]]=0;
	return dep[x]=dep[go[x]]+len[x];
}
int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
void modify(){
	int L=read()-1,R=read()-1,x=read();
	for(int i=BLK[L];i<=BLK[R];i++)rebuild(i,L,R,x);
}
bool lab[100100];
void LCA(){
//	printf("BEF:%d\n",dep[0]);
	int x=read()-1,y=read()-1;
	chain(x),chain(y);
//	printf("AFT:%d\n",dep[0]);
	while(go[x]!=go[y]){
		if(dep[go[x]]<dep[go[y]])swap(x,y);
		x=fa(go[x]);
	}
	lab[0]=true;
	for(int i=x;i&&BLK[i]==BLK[x];i=fa(i))lab[i]=true;
	for(int i=y;BLK[i]==BLK[y];i=fa(i))if(lab[i]){printf("%d\n",i+1);break;}
	for(int i=x;i&&BLK[i]==BLK[x];i=fa(i))lab[i]=false;
}
int main(){
//	freopen("I.in","r",stdin);
	n=read(),m=read(),a[0]=-1;
	for(int i=1;i<n;i++)a[i]=read()-1,BLK[i]=i/BBB;
	lp[num=BLK[n]=BLK[n-1]+1]=n;for(int i=0;i<num;i++)lp[i]=i*BBB;
	for(int i=0;i<num;i++)rebuild(i,-1,-1,0);
	for(int i=1;i<=m;i++)if(read()==1)modify();else LCA();
	return 0;
}