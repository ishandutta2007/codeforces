#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],f[N],t,n;
vector<int> v;
int _0,_1;
inline int check(int x,int y,int z)
{
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	int p;
	scanf("%d",&p);
	return p;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i+=3)
			a[i]=check(i,i+1,i+2);
		for (int i=1;i<=n;i+=3)
			if (a[i]!=a[i+3])
			{
				a[i+1]=check(i+1,i+2,i+3);
				a[i+2]=check(i+2,i+3,i+4);
				for (int j=i;j<=i+2;++j)
					if (a[j]!=a[j+1])
					{
						if (a[j]==0)
						{
							_0=j;
							_1=j+3;
						}
						else
						{
							_0=j+3;
							_1=j;
						}
						break;
					}
				break;
			}
		// cout<<_0<<' '<<_1<<endl;
		f[_0]=0;
		f[_1]=1;
		for (int i=1;i<=n;i+=3)
			if ((_0-i<=2&&_0-i>=0)||(_1-i<=2&&_1-i>=0))
			{
				for (int j=i;j<=i+2;++j)
					if (j!=_0&&j!=_1)
						f[j]=check(_0,_1,j);
			}
			else
			{
				if (a[i]==0)
				{
					if (check(i,i+1,_1)==1)
					{
						f[i]=check(i,_0,_1);
						f[i+1]=!f[i];
						f[i+2]=0;
					}
					else
					{
						f[i]=f[i+1]=0;
						f[i+2]=check(i+2,_0,_1);
					}
				}
				else
				{
					if (check(i,i+1,_0)==0)
					{
						f[i]=check(i,_0,_1);
						f[i+1]=!f[i];
						f[i+2]=1;
					}
					else
					{
						f[i]=f[i+1]=1;
						f[i+2]=check(i+2,_0,_1);
					}
				}
			}
		v.clear();
		for (int i=1;i<=n;++i)
			if (!f[i])
				v.push_back(i);
		printf("! %d",(int)v.size());
		for (int x:v)
			printf(" %d",x);
		puts("");
		fflush(stdout);
	}
}
// 111000111