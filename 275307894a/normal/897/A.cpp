#include<cstdio>
#include<iostream>
using namespace std;
int n,m,k,x,y,z;
char s1,s2,s[10039];
int main(){
	register int i,j;
	scanf("%d%d",&n,&m);
	cin>>s+1;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		cin>>s1>>s2;
		for(j=x;j<=y;j++) if(s[j]==s1) s[j]=s2;
	}
	for(i=1;i<=n;i++)putchar(s[i]);
}