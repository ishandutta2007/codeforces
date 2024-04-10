#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 100100
#define K 80
#define myabs(x) ((x)<0?-(x):(x))
using namespace std;
struct point{
	long long x;
	long long y;
	point(long long _x=0,long long _y=0):x(_x),y(_y){}
	point operator+(point rhs)const{return point(x+rhs.x,y+rhs.y);}
	point operator-(point rhs)const{return point(x-rhs.x,y-rhs.y);}
	long long operator^(point rhs)const{return x*rhs.y-y*rhs.x;}
}p[N<<1];
long long count(point in){
	long long a=myabs(in.x),b=myabs(in.y),tmp;
	while(b>0){
		tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}
int main(){
	double tta2=0,tte=0,ttc;
	double na2,ne,nc,num;
	int n,i,j;
	scanf("%d",&n);
	if(n<60) num=pow(2,n)-1-n-0.5*n*(n-1);
	for(i=0;i<n;i++){
		scanf("%I64d%I64d",&p[i].x,&p[i].y);
		p[n+i]=p[i];
	}
	for(i=0;i<n;i++){
		tta2+=(double)(p[i]^p[i+1]);
		tte+=(double)(count(p[i+1]-p[i]));
	}
	ttc=(tta2+tte+2)/2;
	for(i=1;i<min(n,K);i++){
		if(i>1){
			ne=tte*i;
			na2=tta2*i;
			for(j=0;j<n;j++){
				na2+=(double)(p[j+i]^p[j]);
				ne+=(double)(count(p[j+i]-p[j]));
			}
			nc=(na2+ne)/2;
		}
		else{
			nc=tte;
		}
		if(n<60) ttc-=nc*(pow(2,n-i-1)-1)/num;
		else ttc-=nc/pow(2,i+1);
	}
	printf("%.12f\n",ttc);
	return 0;
}