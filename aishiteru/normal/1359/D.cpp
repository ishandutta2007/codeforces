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
typedef long double ldb;
typedef unsigned long long ull;
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
int n,a[N],ans,o;
int main(){
	scanf("%d",&n);it i;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	for(it j=0;j<=30;++j)
		for(i=1,ans=0;i<=n;++i){
			if(a[i]>j) ans=0;
			else ans=Max(ans+a[i],0);
			o=Max(o,ans-j);
		}
	printf("%d",o);
	return 0;
}

/*
int n,a[N],mx[N][20],sum[N],s[N],top,ans,L[N],R[N],Lg[N];
il int que(ct l,ct r){
	if(l>r) return 0;
	ct k=Lg[r-l+1];
	return Max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int main(){
	scanf("%d",&n);it i;
	s[top=0]=1;
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
		while(top&&a[s[top]]<a[i]) --top;
		L[i]=s[top],s[++top]=i;
	}
	s[top=0]=n;
	for(i=n;i;--i){
		while(top&&a[s[top]]<a[i]) --top;
		R[i]=s[top],s[++top]=i;
	}
	Lg[0]=-1;for(i=1;i<=n;++i) mx[i][0]=sum[i],Lg[i]=Lg[i>>1]+1;Lg[0]=0;
	for(it j=1;(1<<j)<=n;++j)
		for(i=1;i+(1<<j)-1<=n;++i)
			mx[i][j]=Max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
	for(i=1;i<=n;++i) printf("%d %d\n",L[i],R[i]); 
	for(i=1;i<=n;++i) ans=Max(ans,que(L[i],i-1)+que(i+1,R[i]));
	printf("%d",ans);
	return 0;
}
*/