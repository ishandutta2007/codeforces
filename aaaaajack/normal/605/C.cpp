#include<cstdio>
#include<algorithm>
#define N 100100
using namespace std;
struct point{
	int x,y;
	point(){}
	point(int _x,int _y):x(_x),y(_y){}
	point operator-(const point& a)const{return point(x-a.x,y-a.y);}
	long long operator^(const point& a)const{return 1LL*x*a.y-1LL*y*a.x;}
	bool operator<(const point &a)const{return x<a.x||x==a.x&&y>a.y;}
}p[N],v[N];
int main(){
	int n,mx=0,my=0,m=0;
	point g;
	scanf("%d%d%d",&n,&g.x,&g.y);
	for(int i=0;i<n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		if(p[i].x>mx) mx=p[i].x;
		if(p[i].y>my) my=p[i].y;
	}
	p[n++]=point(mx,0);
	p[n++]=point(0,my);
	sort(p,p+n);
	for(int i=0;i<n;i++){
		while(m>=2&&(v[m-1]-v[m-2]^p[i]-v[m-2])>=0) m--;
		v[m++]=p[i];
	}
	for(int i=0;i<m-1;i++){
		if((g^v[i])>=0&&(g^v[i+1])<=0){
			printf("%.12f\n",1.0*(g^v[i]-v[i+1])/(v[i+1]^v[i]));
			break;
		}
	}
	return 0;
}