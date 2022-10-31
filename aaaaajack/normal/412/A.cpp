#include<cstdio>
using namespace std;
int main(){
	char s[200];
	int k,n,i;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	if(n-k<k-1){
		for(i=k;i<n;i++){
			printf("PRINT %c\n",s[i]);
			printf("RIGHT\n");
		}
		printf("PRINT %c\n",s[n]);
		for(i=n-1;i>=1;i--){
			printf("LEFT\n");
			if(i<k) printf("PRINT %c\n",s[i]);
		}
	}
	else{
		for(i=k;i>1;i--){
			printf("PRINT %c\n",s[i]);
			printf("LEFT\n");
		}
		printf("PRINT %c\n",s[1]);
		for(i=2;i<=n;i++){
			printf("RIGHT\n");
			if(i>k) printf("PRINT %c\n",s[i]);
		}
	}
	return 0;
}