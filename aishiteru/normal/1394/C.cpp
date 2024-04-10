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
}
using io :: fr;
const int N=1000005;
template <class I>
il void ckMin(I&p,I q){p=(p<q?p:q);}
template <class I>
il void ckMax(I&p,I q){p=(p>q?p:q);}
int T,len;
char s[N];
int main(){
	scanf("%d",&T);it i,x=0,y=0,lx=1e9,rx=-1e9,ly=1e9,ry=-1e9,lz=1e9,rz=-1e9,ansx=0,ansy=0,ansz=0,ans=1e9;
	while(T--){
		scanf("%s",s+1),len=strlen(s+1),x=y=0;
		for(i=1;i<=len;++i) x+=(s[i]=='B'),y+=(s[i]=='N');
		ckMin(lx,x),ckMax(rx,x),ckMin(ly,y),ckMax(ry,y),ckMin(lz,x-y),ckMax(rz,x-y);
		//printf("0 : %d %d %d %d %d %d %d %d\n",lx,ly,lz,rx,ry,rz,x,y);
	}
	auto ms = [&](){
		auto ck = [&](ct x){return (lx+(x<<1)>=rx)&&(ly+(x<<1)>=ry)&&(lx-ry+(x<<1)+x>=rz);};
		it l=0,r=lz-(lx-ry),mid,ans=1e9;
		if(!ck(r)) return ans;
		while(l<=r) mid=l+r>>1,ck(mid)?ans=mid,r=mid-1:l=mid+1;
		return ans;
	};
	auto sp = [&] (it &x,it &y,it &z){ct xx=y,yy=-z,zz=x;x=xx,y=yy,z=zz;};
	auto swp = [&] (it &p,it &q){ct x=p;p=q,q=x;};
	for(T=1;T<=6;++T){
		i=ms();
		if(i<ans) ans=i,ansx=lx+i,ansy=ry-i,ansz=ansx-ansy;
		//printf("1 : %d %d %d %d %d %d %d %d %d %d\n",lx,ly,lz,rx,ry,rz,ansx,ansy,ansz,ans);
		swp(rz,lz),sp(lx,ly,lz),sp(rx,ry,rz),sp(ansx,ansy,ansz);
		//printf("2 : %d %d %d %d %d %d %d %d %d %d\n",lx,ly,lz,rx,ry,rz,ansx,ansy,ansz,ans);
	}
	printf("%d\n",ans);
	while(ansx--) putchar('B');
	while(ansy--) putchar('N');
	return 0;
}