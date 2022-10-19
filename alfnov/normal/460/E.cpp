#include<bits/stdc++.h>
#define pf(rf,y) (sqrt(1.0*(rf)*(rf)+1.0*(y)*(y)))
#define Len(cdx) pf((cdx.x),(cdx.y))
#define dis(a,b) (pf((a.x-b.x),(a.y-b.y)))
#define eps 1e-7
using namespace std;
struct apple{
	int x,y;
	double arg;
	apple(int x=0,int y=0):x(x),y(y){}
	bool operator<(const apple &other)const{
		if(fabs(arg-other.arg)<eps)return y<other.y;
		return arg<other.arg;
	}
}e[10005];
apple operator-(apple a,apple b){
	return apple(a.x-b.x,a.y-b.y);
}
long long operator^(apple a,apple b){
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
int n,r,gs;
int q[10005];
int xz[105];
long long ans=-1;
vector<pair<int,int>>vv;
void dfs1(int x,int gg,long long he){
	if(gg==n){
		if(ans<he){
			ans=he;
			vv.clear();
			for(int i=1;i<=n;++i)
				vv.emplace_back(make_pair(e[q[xz[i]]].x,e[q[xz[i]]].y));
		}
		return;
	}
	if(x==gs+1)return;
	for(int i=x;i<=gs;++i){
		xz[gg+1]=i;
		long long eh=he;
		int X1=e[q[i]].x,Y1=e[q[i]].y;
		for(int j=1;j<=gg;++j){
			int X2=e[q[xz[j]]].x,Y2=e[q[xz[j]]].y;
			eh+=1ll*(X1-X2)*(X1-X2)+1ll*(Y1-Y2)*(Y1-Y2);
		}
		dfs1(i,gg+1,eh);
	}
}
void dfs2(int x,int gg,long long he){
	if(gg==n){
		if(ans<he){
			ans=he;
			vv.clear();
			for(int i=1;i<=n;++i)
				vv.emplace_back(make_pair(e[q[xz[i]]].x,e[q[xz[i]]].y));
		}
		return;
	}
	if(x==gs)return;
	for(int i=x+1;i<=gs;++i){
		xz[gg+1]=i;
		long long eh=he;
		int X1=e[q[i]].x,Y1=e[q[i]].y;
		for(int j=1;j<=gg;++j){
			int X2=e[q[xz[j]]].x,Y2=e[q[xz[j]]].y;
			eh+=1ll*(X1-X2)*(X1-X2)+1ll*(Y1-Y2)*(Y1-Y2);
		}
		dfs2(i,gg+1,eh);
	}
}
void dfs3(int x,int gg,long long he){
	if(gg==n/2){
		if(ans<he){
			ans=he;
			vv.clear();
			for(int i=1;i<=n/2;++i){
				vv.emplace_back(make_pair(e[q[xz[i]]].x,e[q[xz[i]]].y));
				vv.emplace_back(make_pair(-e[q[xz[i]]].x,-e[q[xz[i]]].y));
			}
		}
		return;
	}
	if(x==gs+1)return;
	for(int i=x;i<=gs;++i){
		xz[gg+1]=i;
		long long eh=he;
		int X1=e[q[i]].x,Y1=e[q[i]].y;
		for(int j=1;j<=gg;++j){
			int X2=e[q[xz[j]]].x,Y2=e[q[xz[j]]].y;
			eh+=2ll*(X1-X2)*(X1-X2)+1ll*(Y1-Y2)*(Y1-Y2);
		}
		X1=
		e[q[i]].x,Y1=-e[q[i]].y;
		for(int j=1;j<=gg;++j){
			int X2=e[q[xz[j]]].x,Y2=e[q[xz[j]]].y;
			eh+=2ll*(X1-X2)*(X1-X2)+1ll*(Y1-Y2)*(Y1-Y2);
		}
		dfs3(i,gg+1,eh);
	}
}
int main(){
	cin>>n>>r;
	int m=0;
	int X=r+1,Y=r+1;
	for(int x=-r;x<=r;++x)for(int y=-r;y<=r;++y){
		if(x*x+y*y>r*r)continue;
		e[++m]=apple(x,y);
		if(Y>y)X=x,Y=y;
		else if(Y==y&&X>x)X=x;
	}
	for(int i=1;i<=m;++i){
		e[i].x-=X,e[i].y-=Y;
		e[i].arg=acos(e[i].x/Len(e[i]));
		if(e[i].x==0&&e[i].y==0)e[i].arg=-1e9;
	}
	sort(e+1,e+m+1);
	gs=0;
	q[++gs]=1;
	for(int i=2;i<=m;++i){
		int flag=1;
		while(gs>=2){
			long long cj=(e[q[gs-1]]-e[q[gs]])^(e[q[gs]]-e[i]);
			if(cj>0)break;
			if(cj==0){
				double c1=dis(e[q[gs-1]],e[q[gs]]);
				double c2=dis(e[q[gs]],e[i]);
				double c3=dis(e[i],e[q[gs-1]]);
				if(fabs(c3-c2-c1)>=eps)flag=0;
			}
			if(!flag)break;
			--gs;
		}
		if(flag)q[++gs]=i;
	}
	for(int i=1;i<=m;++i)e[i].x+=X,e[i].y+=Y;
	if(n>7&&gs>2*n){
		dfs3(0,0,0);
		dfs2(0,0,0);
	}else{
		dfs1(1,0,0);
	}
	printf("%lld\n",ans);
	for(auto cu:vv)printf("%d %d\n",cu.first,cu.second);
	return 0;
}