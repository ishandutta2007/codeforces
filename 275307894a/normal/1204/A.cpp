#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,flag;
char z[514];
int main(){
	cin>>z;
	n=strlen(z);
	for(int i=1;i<n;i++) if(z[i]=='1'){flag=1;break;}
	if(n%2==1&&!flag){printf("%d",n/2);return 0;}
	else if(!(n%2))printf("%d",n/2);
	else printf("%d",n/2+1);
	return 0;
}