#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,k,a1,a2,a3,a4;char s[N];
int main()
{
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++)if(s[i]=='0')a1=a1?a1:i,a2=i;else a3=a3?a3:i,a4=i;
	if(a2-a1<k||a4-a3<k){puts("tokitsukaze");return 0;}
	int p[]={a1,a2,a3,a4};sort(p,p+4);
	if(p[3]-p[1]>k||p[2]-p[0]>k)puts("once again");
	else puts("quailty");
	return 0;
}