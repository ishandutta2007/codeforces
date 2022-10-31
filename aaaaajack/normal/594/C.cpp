#include<cstdio>
#include<algorithm>
#include<utility>
#define N 100100
#define F first
#define S second
using namespace std;
struct point{
	point(){}
	point(int _x,int _y):x(_x),y(_y){}
	int x,y;
};
pair<point,int> sx[N],sy[N];
bool cmpx(pair<point,int> a,pair<point,int> b){return a.F.x<b.F.x;}
bool cmpy(pair<point,int> a,pair<point,int> b){return a.F.y<b.F.y;}
int del[N];
int main(){
	long long ans=(1LL<<60);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		sx[i]=sy[i]=make_pair(point(x1+x2,y1+y2),i);
	}
	sort(sx,sx+n,cmpx);
	sort(sy,sy+n,cmpy);
	for(int ix=0;ix<=k;ix++){
		for(int jx=n-1;jx>=n-1-(k-ix);jx--){
			int dx=max(1,(sx[jx].F.x-sx[ix].F.x+1)/2);
			int now=ix+(n-1-jx);
			for(int iy=0;iy<=k;iy++){
				for(int jy=n-1;jy>=n-1-k&&jy>=iy;jy--){
					int dy=max(1,(sy[jy].F.y-sy[iy].F.y+1)/2);
					if(now<=k){
						ans=min(ans,1LL*dx*dy);
					}
					if(!del[sy[jy].S]) now++;
					del[sy[jy].S]++;
				}
				for(int jy=n-1;jy>=n-1-k&&jy>=iy;jy--){
					del[sy[jy].S]--;
					if(!del[sy[jy].S]) now--;
				}
				if(!del[sy[iy].S]) now++;
				del[sy[iy].S]++;
			}
			for(int iy=0;iy<=k;iy++){
				del[sy[iy].S]--;
				if(!del[sy[iy].S]) now--;
			}
			del[sx[jx].S]++;
		}
		for(int jx=n-1;jx>=n-1-(k-ix);jx--) del[sx[jx].S]--;
		del[sx[ix].S]++;
	}
	printf("%I64d\n",ans);
	return 0;
}