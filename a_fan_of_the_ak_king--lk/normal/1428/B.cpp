#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,t,a,b,x,y,i;
char c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",c+1);
		int ans=0;
		for(i=1;i<=n;++i)
			if(c[i]=='-')
			{
				++ans;
				if(c[i%n+1]!='-')
					++ans;
			}
		bool f1=true,f2=true;
		for(i=1;i<=n;++i)
		{
			if(c[i]!='>'&&c[i]!='-')
				f1=false;
			if(c[i]!='<'&&c[i]!='-')
				f2=false;
		}
		if(f1||f2)
			printf("%d\n",n);
		else
			printf("%d\n",ans);
	}
}