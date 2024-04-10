#include<cstdio>
double f[1009][1009];
double get(int x,int y){
	if(!x)return 1.0/(y+1); 
	if(!y)return 1;
	if(f[x][y])return f[x][y];
	register double a=y*1.0/(y+1)*(1-get(y-1,x)),b=1.0/(y+1)+a,c=1-get(y,x-1),d=(c-1)/(a-1-b+c);
	return f[x][y]=d*a+1-d;
}
int main(){
	register int n,m;
	scanf("%d%d",&n,&m);
	register double s=get(n,m);
	printf("%.11lf %.11lf\n",s,1-s );
	return 0;
}