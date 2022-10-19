#include<cstdio>
#include<iostream>
using namespace std;
int n,m,k,x,y,z,t,flag;
char a[10039];
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		flag=0;
		scanf("%d",&n);
		cin>>a+1;
		for(i=1;i<=n;i++) a[i]-=48;
		if(n&1){
			for(i=1;i<=n;i+=2) if(a[i]&1) flag=1;
			if(flag) printf("1\n");
			else printf("2\n");
		}
		else{
			for(i=2;i<=n;i+=2) if(a[i]%2==0) flag=1;
			if(flag) printf("2\n");
			else printf("1\n");
		}
	}
}