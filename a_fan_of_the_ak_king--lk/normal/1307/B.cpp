
 #include<bits/stdc++.h>
using namespace std;
const int N=100005,M=1000000007;
typedef long double lb;
int n,d,t,i,a[1000005],s,x;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&x);
		s=0;
		bool flag=false;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]==x)
				flag=1;
			s=max(s,a[i]);
		}
		if(flag)
			cout<<1<<endl;
		else
		if(s>x)
			cout<<2<<endl;
		else
			cout<<(x+s-1)/s<<endl;
	}
}