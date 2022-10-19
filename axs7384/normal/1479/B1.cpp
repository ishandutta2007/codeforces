#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	char c=getchar();
	x=0;
	int y=1;
	while (c>'9'||c<'0')
	{
		if (c=='-')
			y=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	x*=y;
}
int n,a[100005];
int len,pre,ppre,cnt,ans;
int main()
{
	read(n);
	for (int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	for (int i=1;i<=n;++i)
	{
		if (a[i]==a[i-1])
			++len;
		else
			len=1;
		//cout<<i<<' '<<len<<endl;
		if (a[i]!=a[i+1])
		{
			// if (i==1)
			// 	continue;
			if (len>=2)
			{
				// cout<<i<<' '<<pre<<' '<<ppre<<' '<<cnt<<endl;
				if (pre!=a[i])
					++ans;
				pre=a[i];
				// cout<<i<<' '<<ans<<endl;
				if (cnt>=2||ppre!=a[i])
					++ans;
				ppre=a[i];
				cnt=1;
				// cout<<i<<' '<<ans<<endl;
			}
			else
			{
				if (pre!=a[i]||ppre!=a[i]||cnt>=2)
				{
					++ans;
					if (pre!=a[i]&&(ppre!=a[i]||cnt>=2))
					{
						if (pre!=ppre)
							cnt=2;
					}
					else
					{
						if (pre==a[i])
						{
							cnt=1;
							ppre=pre;
						}
					}
					pre=a[i];
				}
				// cout<<i<<' '<<ans<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}