#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int t,n,l[N],r[N];
char s[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for (int i=0;i<=n;++i)
			l[i]=r[i]=i;
		for (int i=n-1;i>=0;--i)
			if (s[i+1]=='R')
			{
				if (i+2<=n&&s[i+2]=='L')
					r[i]=r[i+2];
				else
					r[i]=i+1;
			}
		for (int i=1;i<=n;++i)
			if (s[i]=='L')
			{
				if (i>1&&s[i-1]=='R')
					l[i]=l[i-2];
				else
					l[i]=i-1;
			}
		// for (int i=0;i<=n;++i)
		// {
		// 	cout<<'?'<<i<<' '<<l[i]<<' '<<r[i]<<endl;
		// }
		for (int i=0;i<=n;++i)
			printf("%d ",r[i]-l[i]+1);
		putchar('\n');
	}
	return 0;
}