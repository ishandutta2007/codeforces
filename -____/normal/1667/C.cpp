#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,k;
void go(int x){
	int i;
	for(i=1;i<=x/2;i++)
		printf("%d %d\n",i,x/2+1-i);
	for(i=x/2+1;i<=x;i++)
		printf("%d %d\n",i,x/2+1+x-i);
}
int main(){
	scanf("%d",&n);
	k=n*2-1;
	if(n%3==2){
		printf("%d\n",k/3);
		go(k/3);
	}
	if(n%3==0){
		printf("%d\n",k/3+1);
		go(k/3);
		printf("%d %d\n",k/3+1,k/3+1);
	}
	if(n%3==1){
		printf("%d\n",k/3+1);
		go(k/3+1);
	}
	return 0;
}