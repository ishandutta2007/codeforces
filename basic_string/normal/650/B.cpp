#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
char s[N];
int d[N];
int main(){
	int n,a,b,t,i,j,k,w=0;
	scanf("%d%d%d%d%s",&n,&a,&b,&t,s+1),++b;
	for(i=1;i<=n;++i)d[i]=s[i]=='w'?b:1;
	if(d[1]>t)return puts("0"),0;
	for(i=1,j=d[1];j<=t&&i<=n;j+=d[++i]+a);
	w=i-1;
	if(w==n)return printf("%d",w),0;
	for(i=1,j=d[1]+a+d[n];j<=t;j+=d[++i]+a+a);
	for(k=n;j-=d[i--]+a+a,i;){
		while(j<=t)j+=d[--k]+a;
		j-=d[k++]+a,w=max(w,i+n-k+1);
	}
	for(i=n,j=d[1]+a+d[n]+a;j<=t;j+=d[--i]+a+a);
	for(k=1;j-=d[i++]+a+a,i<=n;){
		while(j<=t)j+=d[++k]+a;
		j-=d[k--]+a,w=max(w,k+n-i+1);
	}
	printf("%d",w);
	return 0;
}