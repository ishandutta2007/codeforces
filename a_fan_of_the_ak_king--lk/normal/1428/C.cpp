#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,t,top,b,x,y,i,ans;
char c[N],a[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c+1);
		int n=strlen(c+1);
		ans=top=0;
		for(i=1;c[i];++i)
			if(c[i]=='B')
			{
				if(top)
				{
					ans+=2;
					--top;
				}
				else
					a[++top]=c[i];
			}
			else
				a[++top]=c[i];
		printf("%d\n",i-1-ans);
	}
}