#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN=105,INF=1<<30;

int n,pos,l,r,ans;

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
	scanf("%d%d%d%d",&n,&pos,&l,&r);
	ans=0;
	if(pos<l)
	{
		ans+=l-pos+1;
		if(r!=n)
			ans+=r-l+1;
		printf("%d\n",ans);
	}
	else if(pos>=l&&pos<=r)
	{
		if(l!=1&&r!=n)
		{
			ans+=min(r-pos,pos-l)+1;
			ans+=r-l+1;
			printf("%d\n",ans);
		}
		else if(l==1&&r!=n)printf("%d\n",r-pos+1);
		else if(l!=1&&r==n)printf("%d\n",pos-l+1);
		else if(l==1&&r==n)printf("0\n");
	}
	else if(pos>r)
	{
		ans+=pos-r+1;
		if(l!=1)ans+=r-l+1;
		printf("%d\n",ans);
	}
	return 0;
}