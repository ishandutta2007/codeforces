#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db
#define pb push_back
#define mkp make_pair
#define pl pair<ll,int> 
#define pi pair<int,int> 
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
	}
	template <class I> 
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=-1,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num*=p;
	} 
	template <class I> 
	il I Max(I p,I q){return p>q?p:q;}
	template <class I> 
	il I Min(I p,I q){return p<q?p:q;}
	template <class I> 
	il I A(I x){return x<0?-x:x;}
	template <class I> 
	il void sp(I&p,I&q){I x=p;p=q,q=x;}
	template <class I>
	il void ckMax(I&p,I q){p=(p>q?p:q);}
	template <class I>
	il void ckMin(I&p,I q){p=(p<q?p:q);}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
using io :: ckMax;
using io :: ckMin;
const int N=1000005;
char s[N];
int n,x,f[5005][5005],tag[N],nxt[N],id[N],a[N],b[N],xx;
il bool ck(){
	for(it i=1;i<=*a;++i)
		for(it s=0,j=i;j<=*a;++j){
			s+=a[j]; 
			if(!(xx%s)) return 1;
		}
	return 0;
}
int main(){ 
	scanf("%s%d",s+1,&x),n=strlen(s+1),xx=x,--x;ct lim=(1<<x)-1; it i,j,lst;
	for(i=0;i<=lim;++i){
		a[0]=0,tag[i]=1,lst=-1;
		for(j=0;j<x;++j)
			if(i>>j&1) a[++*a]=j-lst,lst=j;
	//	printf("%d : ",i);for(j=1;j<=a[0];++j) printf("%d ",a[j]);puts("");
		while(ck()) --a[0];
	//	printf("%d : ",i);for(j=1;j<=a[0];++j) printf("%d ",a[j]);puts("");
		for(j=a[0],nxt[i]=0;j;--j)
			nxt[i]<<=a[j],nxt[i]^=(1<<a[j]-1);
		//printf("%d %d\n",nxt[i],a[0]);
		b[++*b]=nxt[i];
	}
	std::sort(b+1,b+1+*b),b[0]=std::unique(b+1,b+1+*b)-b-1;
	for(i=1;i<=*b;++i) id[b[i]]=i,tag[b[i]]=0;//printf("%d ",b[i]);puts("");
	for(i=n;i;--i){
		for(j=1;j<=*b;++j){
			f[i][j]=f[i+1][j]+1;
			it tmp=b[j];tmp<<=(s[i]-'0'),tmp^=(1<<(s[i]-'0'-1));
			if(((tmp>>x)&1)&&(!tag[tmp&lim])) continue;
			f[i][j]=Min(f[i][j],f[i+1][id[nxt[tmp&lim]]]);
		}
	}
	printf("%d",f[1][1]);
	return 0;
}