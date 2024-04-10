#include<bits/stdc++.h>
using namespace std;
int t,n,num[201];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&num[i]),num[i]--;
		bool flag=true;
		for(int i=0;i<n;i++)if(num[i]!=(num[(i+1)%n]+1)%n){flag=false;break;}
		if(flag){puts("YES");continue;}
		flag=true;
		for(int i=0;i<n;i++)if(num[i]!=(num[(i+1)%n]+n-1)%n){flag=false;break;}
		if(flag){puts("YES");continue;}
		puts("NO");
	}
	return 0;
}