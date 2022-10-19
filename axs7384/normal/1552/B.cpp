#include<bits/stdc++.h>
using namespace std;
int t,n;
// struct dt
// {
// 	int a[7];
// 	int id;
// 	bool operator<(const dt&x)const
// 	{
// 		return a[0]<x.a[0];
// 	}
// }a[50005];
int a[50005][7];
inline bool pd(int x,int y)
{
	int ans=0;
	for (int i=1;i<=5;++i)
		if (a[x][i]<a[y][i])
			++ans;
	return ans>=3;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=5;++j)
				scanf("%d",&a[i][j]);
		}
		int now=1;
		for (int i=2;i<=n;++i)
			if (pd(i,now))
				now=i;
		for (int i=1;i<=now;++i)
			if (i!=now&&!pd(now,i))
			{
				now=-1;
				break;
			}
		cout<<now<<endl;
	}
}