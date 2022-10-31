#include<cstdio>
using namespace std;
int main(){
	int n,k,t,i,cnt=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		if(t<=5-k) cnt++;
	}
	printf("%d\n",cnt/3);
	return 0;
}