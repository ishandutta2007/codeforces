#include<stdio.h>
#include<iostream>
using namespace std;
int T,n;
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),cin>>s;
		for(int i=1,k=0;i<=n;i++){
			if(s[i-1]=='U')
				putchar('D');
			else if(s[i-1]=='D')
				putchar('U');
			else if(k==0)
				putchar('L'),k=1;
			else putchar('R'),k=0;
		}
		puts("");
	}
	return 0;
}