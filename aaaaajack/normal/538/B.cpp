#include<cstdio>
using namespace std;
int main(){
	int a,k[20]={},i,r=1,cnt=0;
	scanf("%d",&a);
	while(a){
		for(i=0;i<a%10;i++){
			k[i]+=r;
		}
		a/=10;
		r*=10;
	}
	while(k[cnt]) cnt++;
	printf("%d\n",cnt);
	for(i=0;i<cnt;i++){
		if(i) putchar(' ');
		printf("%d",k[i]);
	}
	putchar('\n');
	return 0;
}