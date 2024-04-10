#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100010
using namespace std;
struct edge{
	int x;
	int y;
	int w;
	edge(int _x=0,int _y=0,int _w=0):x(_x),y(_y),w(_w){}
	bool operator<(edge k)const{return w>k.w;}
} e[N];
int a[N],ds[N],sz[N];
int find(int x){
	if(ds[x]==x) return x;
	return ds[x]=find(ds[x]);
}
bool con(int x,int y){
	return find(x)==find(y);
}
int total(int x){
	return sz[find(x)];
}
void uni(int x,int y){
	sz[find(y)]+=sz[find(x)];
	ds[find(x)]=find(y);
}
int main(){
	int n,m,i;
	double ans=0,d;
	scanf("%d%d",&n,&m);
	d=0.5*n*(n-1);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ds[i]=i;
		sz[i]=1;
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&e[i].x,&e[i].y);
		e[i].w=min(a[e[i].x],a[e[i].y]);
	}
	sort(e,e+m);
	for(i=0;i<m;i++){
		if(!con(e[i].x,e[i].y)){
			ans+=1.0*e[i].w*total(e[i].x)*total(e[i].y)/d;
			uni(e[i].x,e[i].y);
		}
	}
	printf("%.6f\n",ans);
	return 0;
}