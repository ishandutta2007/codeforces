#include<cstdio>
#include<cstring>
using namespace std;
int n,m,xs,ys,ans[1000039],k[100039],a[100039],b[100039],x[100039],y[100039],h1[100039],h2[100039],head1,head2,f[100039],d[100039];
struct yyy{
	int to,z,num;
}f1[1000039],f2[1000039];
inline void add1(int x,int y,int z){
	f1[++head1]=(yyy){y,h1[x],z};
	h1[x]=head1;
}
inline void add2(int x,int y,int z){
	f2[++head2]=(yyy){y,h2[x],z};
	h2[x]=head2;
}
inline int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
inline void tarjan(int x,int last,int dis){
	d[x]=dis;
	int cur=h1[x];
	yyy tmp;
	while(cur!=-1){
		tmp=f1[cur];
		if(tmp.to!=last)tarjan(tmp.to,x,dis+1),f[find(tmp.to)]=find(x);
		cur=tmp.z;
	}
	cur=h2[x];
	while(cur!=-1){
		tmp=f2[cur];
		if(d[tmp.to]&&tmp.to!=last) ans[tmp.num]=find(tmp.to);
		cur=tmp.z;
	}
}
int main(){
	memset(h1,-1,sizeof(h1));
	memset(h2,-1,sizeof(h2));
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<n;i++) scanf("%d%d",&xs,&ys),add1(xs,ys,0),add1(ys,xs,0);
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d%d%d",&x[i],&y[i],&a[i],&b[i],&k[i]);
		add2(a[i],b[i],i*5-4);add2(b[i],a[i],i*5-4);
		add2(a[i],x[i],i*5-3);add2(x[i],a[i],i*5-3);add2(b[i],x[i],i*5-2);add2(x[i],b[i],i*5-2);
		add2(a[i],y[i],i*5-1);add2(y[i],a[i],i*5-1);add2(b[i],y[i],i*5);add2(y[i],b[i],i*5);
	}
	tarjan(1,0,1);
	//printf("1\n");
	for(i=1;i<=m;i++){
		//printf("%d %d %d %d %d\n",ans[i*5-4],ans[i*5-3],ans[i*5-2],ans[i*5-1],ans[i]);
		if((d[a[i]]+d[b[i]]-d[ans[i*5-4]]*2)%2==k[i]%2&&d[a[i]]+d[b[i]]-d[ans[i*5-4]]*2<=k[i]) printf("YES\n");
		else if(d[a[i]]+d[x[i]]-d[ans[i*5-3]]*2+1+d[b[i]]+d[y[i]]-d[ans[i*5]]*2<=k[i]&&(d[a[i]]+d[x[i]]-d[ans[i*5-3]]*2+1+d[b[i]]+d[y[i]]-d[ans[i*5]]*2)%2==k[i]%2) printf("YES\n");
		else  if(d[a[i]]+d[y[i]]-d[ans[i*5-1]]*2+1+d[b[i]]+d[x[i]]-d[ans[i*5-2]]*2<=k[i]&&(d[a[i]]+d[y[i]]-d[ans[i*5-1]]*2+1+d[b[i]]+d[x[i]]-d[ans[i*5-2]]*2)%2==k[i]%2) printf("YES\n");
		else printf("NO\n");
	}
}