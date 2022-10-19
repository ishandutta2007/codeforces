#include<bits/stdc++.h>
using namespace std;
int x,y,lx,ly,Test_num;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline int one(int x)
{
	int res=0;
	while(x)res+=(x&1),x>>=1;
	return res;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(x),read(y);
		if(x>y){puts("NO");continue;}
		else
		{
			while(1)
			{
				if((lx=lowbit(x))>(ly=lowbit(y))){puts("NO");break;}
				x-=lx,y-=ly;
				if(!y){puts("YES");break;}
				if(!x){puts("NO");break;}
			}
		}
	}
	return 0;
}