#include<cstdio>
#include<utility>
#include<algorithm>
#define Q 1000000007
#define N 100100
#define M 2010
#define x first
#define y second
using namespace std;
int fac[N<<1],invfac[N<<1];
int dis[M];
int get_inv(int x){
	int r=1,y=Q-2;
	while(y){
		if(y&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		y>>=1;
	}
	return r;
}
inline int cal(int n,int m){
	return 1LL*fac[n+m]*invfac[n]%Q*invfac[m]%Q;
}
int main(){
	fac[0]=invfac[0]=1;
	for(int i=1;i<(N<<1);i++){
		fac[i]=1LL*fac[i-1]*i%Q;
		invfac[i]=get_inv(fac[i]);
	}
	int h,w,n;
	pair<int,int> point[M];
	scanf("%d%d%d",&h,&w,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&point[i].x,&point[i].y);
		point[i].x--;
		point[i].y--;
	}
	sort(point,point+n);
	point[n++]=make_pair(h-1,w-1);
	for(int i=0;i<n;i++){
		dis[i]=cal(point[i].x,point[i].y);
		for(int j=0;j<i;j++){
			if(point[i].x>=point[j].x&&point[i].y>=point[j].y){
				dis[i]-=1LL*dis[j]*cal(point[i].x-point[j].x,point[i].y-point[j].y)%Q;
				if(dis[i]<0) dis[i]+=Q;
			}
		}
	}
	printf("%d\n",dis[n-1]);
	return 0;
}