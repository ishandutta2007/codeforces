#include<bits/stdc++.h>
#define N 500100
using namespace std;
char op[N];
int num[N];
int main(){
	int n,xa=1023,xo=0,xx=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf(" %c%d",&op[i],&num[i]);
	}
	for(int i=0;i<10;i++){
		int fl=0;
		for(int j=n-1;j>=0;j--){
			if(op[j]=='|'&&(num[j]>>i)%2==1){
				if(!fl) xo|=1<<i;
				else xa&=~(1<<i);
				fl=-1;
				break;
			}
			else if(op[j]=='&'&&(num[j]>>i)%2==0){
				if(!fl) xa&=~(1<<i);
				else xo|=1<<i;
				fl=-1;
				break;
			}
			else if(op[j]=='^'){
				fl^=(num[j]>>i)%2;
			}
		}
		if(fl==1){
			xx^=1<<i;
		}
	}
	printf("%d\n",3);
	printf("| %d\n",xo);
	printf("& %d\n",xa);
	printf("^ %d\n",xx);
	return 0;
}