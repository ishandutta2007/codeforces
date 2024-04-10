#include<cstdio>
#include<iostream>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,ans=1e9,tot,pus,q[1000039];
char s[1000039];
int main(){
	register int i;
	cin>>s+1;
	n=strlen(s+1);
	for(i=1;i<=n;i++) if(s[i]>='A'&&s[i]<='Z') q[i]=1;
	for(i=1;i<=n;i++)q[i]+=q[i-1];
	for(i=0;i<=n;i++)ans=min(ans,i-q[i]+q[n]-q[i]);
	printf("%d\n",ans);
}