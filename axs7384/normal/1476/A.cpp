#include<bits/stdc++.h>
using namespace std;
// #define int long long
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
int t,x,y;
int main()
{
	read(t);
	while (t--)
	{
		read(x);
		read(y);
		if (x==y)
			puts("1");
		else
		{
			if (x>y)
			{
				if (x%y==0)
					puts("1");
				else
					puts("2");
			}
			else
				cout<<(y-1)/x+1<<endl;
		}
	}
}