#include<cstdio>
using namespace std;
int main(){
	int pre=1,now=2,n,h,d;
	scanf("%d%d%d",&n,&d,&h);
	if(d>h+h||d==1&&n>2){
		puts("-1");
	}
	else{
		for(int i=0;i<h;i++){
			printf("%d %d\n",pre,now);
			pre=now;
			now++;
		}
		pre=1;
		for(int i=0;i<d-h;i++){
			printf("%d %d\n",pre,now);
			pre=now;
			now++;
		}
		while(now<=n){
			printf("%d %d\n",h>1?2:1,now);
			now++;
		}
	}
	return 0;
}