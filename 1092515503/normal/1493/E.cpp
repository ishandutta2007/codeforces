#include<bits/stdc++.h>
using namespace std;
int n;
char l[1001000],r[1001000];
void func(){
	bool ok=true;
	for(int i=0;i<n;i++)ok&=(l[i]==r[i]);
	if(ok)return;
	int p=n-1;
	while(p>=0&&r[p]=='0')p--;
	if(p<0)return;
	r[p]='0';for(int j=p+1;j<n;j++)r[j]='1';
	ok=false;
	for(int i=0;i<n;i++)if(l[i]!=r[i])ok=true;
	r[p]='1';for(int j=p+1;j<n;j++)r[j]='0';
	if(ok)r[n-1]='1';
}
int main(){
	scanf("%d%s%s",&n,l,r);
	if(l[0]!=r[0]){for(int i=0;i<n;i++)putchar('1');return 0;}
	if(r[n-1]=='0')func();
	printf("%s\n",r);
	return 0;
}