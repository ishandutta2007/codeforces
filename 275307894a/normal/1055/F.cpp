#include<cstdio>
#include<cstring>
using namespace std;
int n,m,d,tot,now,last,p[1000039],pl[1000039];
long long q[1000039],k,x,y,z,ans,pus;
struct yyy{int to;long long w;int z;};
struct ljb{
	int head,h[1000039];
	yyy f[2000039];
	inline void add(int x,int y,long long z){
		f[++head]=(yyy){y,z,h[x]};
		h[x]=head;
	}
}s;
struct tree{int l,r,f;}f[2][1000039];
static char buf[1000000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline void read(long long &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=x*10+s-48,s=getchar();
}
inline void dfs(int x,int last){
	int cur=s.h[x];
	yyy tmp;
	while(cur!=-1){
		tmp=s.f[cur];
		if(tmp.to!=last) q[tmp.to]=q[x]^tmp.w,dfs(tmp.to,x);
		cur=tmp.z;
	}
}
int main(){
//	freopen("1.in","r",stdin);
	memset(s.h,-1,sizeof(s.h));
	register int i;
	scanf("%d%lld",&n,&k);k=(long long)n*n+1-k;
	for(i=2;i<=n;i++) read(x),read(z),s.add(x,i,z),s.add(i,x,z);
	dfs(1,0);
	d=62;
	for(i=1;i<=n;i++) p[i]=1,pl[i]=1;
	while(d!=-1){
		last=now;now=last^1;
		tot=0;
		for(i=1;i<=n;i++) f[now][i].l=f[now][i].r=f[now][i].f=0;
		for(i=1;i<=n;i++){
			if(!(q[i]&(1ll<<d))) {
				if(!f[last][p[i]].l) f[last][p[i]].l=++tot;
				p[i]=f[last][p[i]].l;f[now][p[i]].f++;
			}
			else{
				if(!f[last][p[i]].r) f[last][p[i]].r=++tot;
				p[i]=f[last][p[i]].r;f[now][p[i]].f++;
			}
		} 
		ans=0;
		for(i=1;i<=n;i++){
			if(q[i]&(1ll<<d))ans+=f[now][f[last][pl[i]].l].f;
			else ans+=f[now][f[last][pl[i]].r].f;
		}
	//	printf("%d %lld %lld\n",d,ans,k);
		if(ans>=k){
			pus^=(1ll<<d);
			for(i=1;i<=n;i++){
			    if(q[i]&(1ll<<d))pl[i]=f[last][pl[i]].l;
		    	else pl[i]=f[last][pl[i]].r;
	    	}
		}
		else{
			k-=ans;
			for(i=1;i<=n;i++){
			    if(q[i]&(1ll<<d))pl[i]=f[last][pl[i]].r;
		    	else pl[i]=f[last][pl[i]].l;
	    	}
		}
		d--;
	}
	printf("%lld\n",pus);
}