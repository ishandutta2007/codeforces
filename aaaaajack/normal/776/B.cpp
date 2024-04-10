#include<bits/stdc++.h>
#define N 100100
using namespace std;
bool notp[N];
int main(){
	for(int i=2;i<N;i++){
		for(int j=2;i*j<N;j++){
			notp[i*j]=true;
		}
	}
	int n;
	scanf("%d",&n);
	if(n>=3) printf("%d\n",2);
	else printf("%d\n",1);
	for(int i=2;i<=n+1;i++){
		if(i>2) putchar(' ');
		if(notp[i]) printf("%d",2);
		else printf("%d",1);
	}
	puts("");
	return 0;
}