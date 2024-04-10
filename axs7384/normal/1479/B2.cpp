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
int n,a[100005],ans;
set<int> s;
int main()
{
	read(n);
	/*for (int i=1;i<=n;++i)
	{
		read(a[i]);
		if (a[i]!=a[i-1])
		{
			ans+=min(len,2);
			len=1;
			pre=a[i];
		}
		else
			++len;
	}*/
	// for (int i=1;i<=n;++i)
	// {
	// 	read(a[i]);
	// 	if (a[i]!=a[i-1])
	// 	{
	// 		if (len>=2)
	// 		{
	// 			if ()
	// 		}
	// 		else
	// 		{
	// 			++ans;
	// 			if (ti)
	// 			{
	// 				pre=0;
	// 				ti=0;
	// 			}
	// 			else
	// 				ti=1;
	// 		}
	// 	}
	// 	else
	// 		++len;
	// }
	// ans+=min(len,2);
	// cout<<ans;
	ans=0;
	for (int i=1;i<=n;++i)
	{
		read(a[i]);
		if (a[i]==a[i-1])
			continue;
		if (s.count(a[i]))
		{
			s.clear();
			s.insert(a[i-1]);
		}
		else
		{
			++ans;
			s.insert(a[i-1]);
		}
		// cout<<i<<' '<<ans<<endl;
	}
	cout<<ans;
	return 0;
}