#include<bits/stdc++.h>
using namespace std;
const int N=300005;
char c[3][N];
int f[10][3];
int n,t;
inline void solve(int x,int y,int z)
{
	if (f[x][z]<f[y][z])
		swap(x,y);
	// cout<<x<<' '<<y<<endl;
	int p=f[y][z],l=0,r=0,sx,sy,cnt=0;
	for (int i=1;i<=f[y][z];++i)
	{
		sx=sy=0;
		while (c[x][l]!=z+'0')
		{
			++l;
			++sx;
		}
		while (c[y][r]!=z+'0')
		{
			++r;
			++sy;
		}
		cnt+=max(sx,sy)+1;
		for (int j=1;j<=max(sx,sy);++j)
			putchar('0'+(1-z));
		putchar('0'+z);
		++l;
		++r;
	}
	// cout<<cnt<<endl;
	for (int i=l;i<2*n;++i)
	{
		++cnt;
		putchar(c[x][i]);
	}
	for (int i=r;i<2*n;++i)
	{
		++cnt;
		putchar(c[y][i]);
	}
	for (int i=cnt+1;i<=3*n;++i)
		putchar('0'+1-z);
	putchar('\n');
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=0;i<3;++i)
		{
			scanf("%s",c[i]);
			f[i][0]=0;
			for (int j=0;j<2*n;++j)
				if (c[i][j]=='0')
					++f[i][0];
			f[i][1]=2*n-f[i][0];
			// cout<<i<<' '<<f[i][0]<<' '<<f[i][1]<<endl;
		}
		bool b=false;
		for (int i=0;i<3;++i)
		{
			for (int j=i+1;j<3;++j)
			{
				if (min(f[i][0],f[j][0])>=n)
				{
					solve(i,j,0);
					b=true;
					break;
				}
				if (min(f[i][1],f[j][1])>=n)
				{
					solve(i,j,1);
					b=true;
					break;
				}
			}
			if (b)
				break;
		}
	}
	return 0;
}