#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int x=sqrt(n/2)+0.25;
		if(2*x*x==n){puts("YES");continue;}
		x=sqrt(n/4)+0.25;
		if(4*x*x==n){puts("YES");continue;}
		puts("NO");
	}
	return 0;
}