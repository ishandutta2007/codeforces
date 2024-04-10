#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,i,j,k,l,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&i,&j,&k,&l);
		if(i==k)n=abs(j-l);
		else if(j==l)n=abs(i-k);
		else n=abs(i-k)+2+abs(j-l);
		printf("%d\n",n);
	}
	return 0;
}