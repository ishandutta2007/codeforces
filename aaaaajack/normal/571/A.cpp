#include<cstdio>
using namespace std;
inline long long count(int x){
	if(x<0) return 0;
	return 1LL*(x+1)*(x+2)/2;
}
int main(){
	int a,b,c,l,i,da,db,dc,sum;
	long long ans=0;
	scanf("%d%d%d%d",&a,&b,&c,&l);
	for(int i=0;i<=l;i++){	
		sum=a+b+c+i;
		da=(sum-1)/2-a+1;
		db=(sum-1)/2-b+1;
		dc=(sum-1)/2-c+1;
		if(da<0||db<0||dc<0) continue;
		ans+=count(i);
		ans-=count(i-da);
		ans-=count(i-db);
		ans-=count(i-dc);
		ans+=count(i-da-db);
		ans+=count(i-db-dc);
		ans+=count(i-da-dc);
		ans-=count(i-da-db-dc);
	}
	printf("%I64d\n",ans);
	return 0;
}