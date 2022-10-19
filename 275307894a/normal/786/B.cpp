#include<cstdio>
#include<queue>
#include<cstring>
#define l(x) x<<1
#define r(x) x<<1|1
#define beg(x) int cur=s.h[x]
#define end cur
#define go cur=tmp.z
using namespace std;
int n,m,k,x,y,z,sx,l,r,cnt,id1[400039],id2[400039],id[100039];
long long d[900039];
struct yyy{int to,w,z;}tmp;
struct ljb{
	int head,h[900039];
	yyy f[10000039];
	inline void add(int x,int y,int z){
		f[++head]=(yyy){y,z,h[x]};
		h[x]=head;
	}
}s;
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=x*10+s-48,s=getchar();
}
inline void jianshu1(int l,int r,int now){
	if(l==r) {id1[now]=id[l];return;}
	id1[now]=++cnt;
	int m=(l+r)>>1;
	jianshu1(l,m,l(now));jianshu1(m+1,r,r(now));
	s.add(id1[now],id1[l(now)],0);s.add(id1[now],id1[r(now)],0);
}
inline void jianshu2(int l,int r,int now){
	if(l==r) {id2[now]=id[l];return;}
	id2[now]=++cnt;
	int m=l+r>>1;
	jianshu2(l,m,l(now));jianshu2(m+1,r,r(now));
	s.add(id2[l(now)],id2[now],0);s.add(id2[r(now)],id2[now],0);
}
inline void get1(int x,int y,int z,int w,int l,int r,int now){
	if(x<=l&&r<=y){s.add(id[z],id1[now],w);return;}
	int m=l+r>>1;
	if(x<=m) get1(x,y,z,w,l,m,l(now));
	if(y>m) get1(x,y,z,w,m+1,r,r(now));
}
inline void get2(int x,int y,int z,int w,int l,int r,int now){
	if(x<=l&&r<=y){s.add(id2[now],id[z],w);return;}
	int m=l+r>>1;
	if(x<=m) get2(x,y,z,w,l,m,l(now));
	if(y>m) get2(x,y,z,w,m+1,r,r(now));
}
struct ques{
	int to;long long w;
	inline bool operator <(const ques &x) const{return w>x.w;}
}tmps;
priority_queue<ques> q;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) id[i]=++cnt;
	jianshu1(1,n,1);jianshu2(1,n,1);
	while(m--){
		read(sx);
		if(sx==1){
			read(x);read(y);read(z);
			s.add(x,y,z);
		}
		else if(sx==2){
			read(x);read(l);read(r);read(z);
			get1(l,r,x,z,1,n,1);
		}
		else if(sx==3){
			read(x);read(l);read(r);read(z);
			get2(l,r,x,z,1,n,1);
		}
	} 
	memset(d,0x3f,sizeof(d));
	d[k]=0;q.push((ques){k,0});
	while(!q.empty()){
		tmps=q.top();q.pop();
		for(beg(tmps.to);end;go){
			tmp=s.f[cur];
			if(d[tmp.to]>d[tmps.to]+tmp.w) d[tmp.to]=d[tmps.to]+tmp.w,q.push((ques){tmp.to,d[tmp.to]});
		}
	}
	for(i=1;i<=n;i++) printf("%lld ",d[i]<1e15?d[i]:-1);
}