#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)
inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10+'0');
}
const int N=1.5e7+5;
int n,q,node=1,ls[N],rs[N],val[N],laz[N];
void push(int l,int r,int x){
	if(laz[x]==-1)return;
	if(!ls[x])ls[x]=++node;
	if(!rs[x])rs[x]=++node;
	int m=l+r>>1;
	laz[ls[x]]=laz[rs[x]]=laz[x];
	val[ls[x]]=laz[x]*(m-l+1),val[rs[x]]=laz[x]*(r-m);
	laz[x]=-1;
}
void modify(int l,int r,int ql,int qr,int &x,int v){
	if(!x)x=++node;
	if(ql<=l&&r<=qr){
		val[x]=v*(r-l+1);
		laz[x]=v;
		return;
	}
	int m=l+r>>1; push(l,r,x);
	if(ql<=m)modify(l,m,ql,qr,ls[x],v);
	if(m<qr)modify(m+1,r,ql,qr,rs[x],v);
	val[x]=val[ls[x]]+val[rs[x]];
}
int main(){
	memset(laz,-1,sizeof(laz));
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		int l=read(),r=read(),k=read(),x=1;
		modify(1,n,l,r,x,k==1);
		print(n-val[1]),pc('\n');
	}
	return flush(),0;
}