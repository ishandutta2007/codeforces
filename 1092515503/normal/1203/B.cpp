#include<bits/stdc++.h>
using namespace std;
int t,n,num[4001],area;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=4*n;i++)scanf("%d",&num[i]);
		sort(num+1,num+4*n+1);
		area=num[1]*num[4*n];
		bool flag=true;
		for(int i=1;i<=2*n;i++){
			if(num[i*2-1]!=num[i*2]||num[(2*n-i)*2+1]!=num[(2*n-i)*2+2]){flag=false;break;}
			if(num[i*2]*num[(2*n-i)*2+1]!=area){flag=false;break;}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}