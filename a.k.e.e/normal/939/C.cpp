#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN=100005;

int a[MAXN],S[MAXN],n,b,e;

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		S[i]=S[i-1]+a[i];
	}
	scanf("%d%d",&b,&e);
	
	int ans=0,t,k;
	for(int i=1;i<=n;i++)
	{
		if(i<=b)t=S[e-i]-S[b-i];
		else if(i>e)t=S[e-i+n]-S[b-i+n];
		else t=S[e-i]+S[n]-S[b-i+n];
		if(t>ans)
		{
			ans=t;
			k=i;
		}
	}
	cout<<k<<endl;
    return 0;
}