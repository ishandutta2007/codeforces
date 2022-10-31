#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const long long inf=1000000000000000ll;
int n,c,i,f[N],pre[N],j,a;
int main()
{
	scanf("%d",&c);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a);
		++f[a];
	}
	for(i=1;i<=c;++i)
		if(!f[i])
			pre[i]=pre[i-1];
		else
			pre[i]=i;
	for(i=1;i<=c;++i)
	{
		int tmp=c;
		++f[i];
		bool flag=true;
		for(j=pre[c];j&&tmp;j=pre[j-1])
		{
			if(f[i]==1&&j<i&&flag)
			{
				j=i;
				flag=false;
			}
			tmp=max(tmp-1ll*j*f[j],1ll*tmp%j);
			j=min(j,tmp+1);
		}
		--f[i];
		if(tmp)
			break;
	}
	if(i>c)
		cout<<"Greed is good";
	else
		cout<<i;
}