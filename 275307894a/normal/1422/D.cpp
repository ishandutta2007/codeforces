#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x[100039],y[100039],z,now,cur,flag[100039];
long long d[100039],ans=1e15;
struct yyy{int to;long long w; int z;}tmps;
struct ljb{
	int head,h[100039];
	yyy f[600039];
	inline void add(int x,int y,long long z){
		f[++head]=(yyy){y,z,h[x]};
		h[x]=head;
	}
}s;
struct tree{int x,y,num;}f[100039];
inline bool cmp1(tree x,tree y){return x.x<y.x;}
inline bool cmp2(tree x,tree y){return x.y<y.y;}
inline bool cmp3(tree x,tree y){return x.num<y.num;}
inline int calc(int a,int b){return min(abs(x[a]-x[b]),abs(y[a]-y[b]));}
inline int calc1(int a,int b){return abs(x[a]-x[b])+abs(y[a]-y[b]);}
struct ques{
	int to;long long w;
	bool operator <(const ques &x) const{return w>x.w;}
}tmp;
priority_queue<ques> q;
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	memset(d,0x3f,sizeof(d));
	memset(s.h,-1,sizeof(s.h));
	register int i;
	scanf("%d%d",&n,&n);
	scanf("%d%d%d%d",&x[0],&y[0],&x[n+1],&y[n+1]);
	ans=abs(x[0]-x[n+1])+abs(y[0]-y[n+1]);
	for(i=1;i<=n;i++) scanf("%d%d",&f[i].x,&f[i].y),x[i]=f[i].x,y[i]=f[i].y,f[i].num=i;
	sort(f+1,f+n+1,cmp1);
	for(i=2;i<=n;i++)s.add(f[i-1].num,f[i].num,calc(f[i-1].num,f[i].num)),s.add(f[i].num,f[i-1].num,calc(f[i-1].num,f[i].num));
	sort(f+1,f+n+1,cmp2);
	for(i=2;i<=n;i++)s.add(f[i-1].num,f[i].num,calc(f[i-1].num,f[i].num)),s.add(f[i].num,f[i-1].num,calc(f[i-1].num,f[i].num));
	for(i=1;i<=n;i++) s.add(0,i,calc(0,i));
	for(i=1;i<=n;i++) s.add(i,n+1,calc1(i,n+1));
	q.push((ques){0,0});
	d[0]=0;
	while(!q.empty()){
		tmp=q.top();
		q.pop();
	//	printf("%d %lld\n",tmp.to,tmp.w);
		cur=s.h[tmp.to];
		while(~cur){
			tmps=s.f[cur];
			if(d[tmps.to]>d[tmp.to]+tmps.w)d[tmps.to]=d[tmp.to]+tmps.w,q.push((ques){tmps.to,d[tmps.to]});
			cur=tmps.z;
		}
	}
	printf("%lld\n",min(d[n+1],ans));
}