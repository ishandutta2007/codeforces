#include<cstdio>
#include<algorithm>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
struct point{
	long long x;
	long long y;
	point(){}
	point(long long _x,long long _y):x(_x),y(_y){}
	point operator-(point r)const{return point(x-r.x,y-r.y);}
	long long operator^(point r)const{return x*r.y-y*r.x;}
}hill[100010];
int par[100010][20],depth[100010];

long long tri(int a,int b,int c){
	return (hill[b]-hill[a])^(hill[c]-hill[a]);
}
int go(int now,int n){
	int j=0;
	for(j=0;j<20;j++){
		if(n&(1<<j)) now=par[now][j];
	}
	return now;
}
int lca(int a,int b){
	if(depth[a]>depth[b]) a=go(a,depth[a]-depth[b]);
	else b=go(b,depth[b]-depth[a]);
	int r=19;
	while(a!=b){
		while(r&&par[a][r]==par[b][r]) r--;
		a=par[a][r],b=par[b][r];
	}
	return a;
}
int main(){
	int i,j,n;
	vector<int> s;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%I64d%I64d",&hill[i].x,&hill[i].y);
	s.push_back(n);
	par[n][0]=n;
	for(i=n-1;i>=1;i--){
		while(s.size()>=2){
			if(tri(s[s.size()-2],s[s.size()-1],i)>=0) break;
			s.pop_back();
		}
		par[i][0]=s.back();
		s.push_back(i);
	}
	memset(depth,-1,sizeof(depth));
	depth[n]=0;
	for(j=1;j<20;j++){
		for(i=1;i<=n;i++){
			if(depth[i]==-1&&depth[par[i][j-1]]>=0) depth[i]=depth[par[i][j-1]]+(1<<j-1);
			par[i][j]=par[par[i][j-1]][j-1];
		}
	}
	//for(i=1;i<=n;i++) printf("%d\n",par[i][0]);
	int m,a,b;
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&a,&b);
		printf("%d",lca(a,b));
		putchar(m?' ':'\n');
	}
	return 0;
}