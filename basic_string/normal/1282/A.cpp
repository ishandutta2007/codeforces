#include<cstdio>
 //
int main(){
	int t,a,b,c,r,x,y,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a,&b,&c,&r);
		x=c-r,y=c+r;
		if(a>b)i=a,a=b,b=i;
		if(x<a)x=a;
		if(b<y)y=b;
		if(x>b)x=b;
		if(y<a)y=a;
		printf("%d\n",b-a-y+x);
	}
	return 0;
}