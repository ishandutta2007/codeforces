#include<bits/stdc++.h>
using namespace std;
#define int long long
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
const int N=100005;
int t,ans,now;
int n;
int a[N],b[N],c[N];
signed main()
{
	read(t);
	while (t--)
	{
		read(n);
		for (int i=1;i<=n;++i)
			read(a[i]);
		for (int i=1;i<=n;++i)
			read(b[i]);
		for (int i=1;i<=n;++i)
			read(c[i]);
		for (int i=1;i<=n;++i)
			if (b[i]>c[i])
				swap(b[i],c[i]);
		ans=0;
		now=c[2]-b[2];
		// puts("???");
		for (int i=3;i<=n;++i)
		{
			now+=2+(b[i]-1)+(a[i-1]-c[i]);
			ans=max(ans,now+c[i]-b[i]);
			// cout<<now+c[i]-b[i]<<' '<<i-1<<endl;
			now=max(now,c[i]-b[i]);
			if (b[i]==c[i])
				now=0;
		}
		// cout<<now+2+a[n]-1<<' '<<n<<endl;
		// puts("!!!");
		ans=max(ans,now+2+a[n]-1);
		cout<<ans<<endl;
	}
	return 0;
}