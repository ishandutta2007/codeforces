#include<cstdio>
#include<cmath>
using namespace std;
inline long long dis2(int x,int y){
	return 1LL*x*x+1LL*y*y;
}
int main(){
	int x1,y1,x2,y2,vx,vy,wx,wy;
	double l=0,r=2e9,xt,yt;
	int v,t,xc,yc;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d%d",&v,&t);
	scanf("%d%d",&vx,&vy);
	scanf("%d%d",&wx,&wy);
	x2-=x1,y2-=y1;
	xc=vx*t,yc=vy*t;
	if(dis2(x2-xc,y2-yc)<=1LL*(v*t)*(v*t)){
		l=0,r=t;
		for(int i=0;i<100;i++){
			double m=(l+r)/2;
			xt=vx*m-x2;
			yt=vy*m-y2;
			if(xt*xt+yt*yt<m*m*v*v) r=m;
			else l=m;
		}
		printf("%.10f\n",l);
	}
	else{
		for(int i=0;i<100;i++){
			double m=(l+r)/2;
			xt=xc-(x2-wx*m);
			yt=yc-(y2-wy*m);
			if(xt*xt+yt*yt<(t+m)*(t+m)*v*v) r=m;
			else l=m;
		}
		printf("%.10f\n",t+l);
	}
	return 0;
}