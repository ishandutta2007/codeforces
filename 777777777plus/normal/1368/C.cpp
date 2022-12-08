#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main(){
	scanf("%d",&n);
	printf("%d\n",4+3*n);
	printf("0 0\n1 0\n0 1\n1 1\n");
	for(int i=1;i<=n;++i){
		printf("%d %d\n",i+1,i+1);
		printf("%d %d\n",i,i+1);
		printf("%d %d\n",i+1,i);
	}
}