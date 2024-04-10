#include<bits/stdc++.h>
using namespace std;
int h,m,h1,m1,h2,m2,t,Test_num;
int a[102];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool work()
{
	h2=m2=0,t=h1/10;
	switch(t)
	{
		case 3:case 4:case 6:case 7:case 9:return 0;
		case 0:t=0;break;
		case 1:t=1;break;
		case 2:t=5;break;
		case 5:t=2;break;
		case 8:t=8;break;
	}
	m2+=t,t=h1%10;
	switch(t)
	{
		case 3:case 4:case 6:case 7:case 9:return 0;
		case 0:t=0;break;
		case 1:t=1;break;
		case 2:t=5;break;
		case 5:t=2;break;
		case 8:t=8;break;
	}
	m2+=10*t,t=m1/10;
	switch(t)
	{
		case 3:case 4:case 6:case 7:case 9:return 0;
		case 0:t=0;break;
		case 1:t=1;break;
		case 2:t=5;break;
		case 5:t=2;break;
		case 8:t=8;break;
	}
	h2+=t,t=m1%10;
	switch(t)
	{
		case 3:case 4:case 6:case 7:case 9:return 0;
		case 0:t=0;break;
		case 1:t=1;break;
		case 2:t=5;break;
		case 5:t=2;break;
		case 8:t=8;break;
	}
	h2+=10*t;
	if(m2>=m || h2>=h)return 0;
	return 1;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(h),read(m),read(h1),read(m1);
		for(;!work();)
		{
			++m1;
			if(m1==m)
			{
				m1=0,++h1;
				if(h1==h)
				{
					h1=0;
					break;
				}
			}
		}
		if(h1<10)printf("0");
		printf("%d:",h1);
		if(m1<10)printf("0");
		printf("%d\n",m1);
	}
	return 0;
}