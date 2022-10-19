#include<cstdio>
int n,x,Test_num;
bool odd,even;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		odd=even=0,read(n);
		for(int i=1;i<=n;++i)
		{
			read(x);
			if(x&1)odd=1;
			else even=1;
		}
		if(odd && even)puts("NO");
		else puts("YES");
	}
	return 0;
}