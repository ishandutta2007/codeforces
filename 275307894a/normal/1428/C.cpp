#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;;
char c,a[200039];
int n,m,k,x,y,z,t,ans,now,tot;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		cin>>a+1;
		n=strlen(a+1);
		now=0;
		for(i=1;i<=n;i++)if(a[i]=='B') now++;
		ans=0;tot=0;
		for(i=n;i>=1;i--){
			if(a[i]=='A') ans--;
			if(a[i]=='B') ans++;
			if(ans>=0&&a[i]=='A') now--,tot++;
			if(ans<0) ans=0;
		}
		printf("%d\n",n-(tot+now/2)*2);
	}
}