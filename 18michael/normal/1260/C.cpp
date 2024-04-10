#include<cstdio>
int p1,p2,k,t,Test_num;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int gcd(int a,int b)
{
	return b? gcd(b,a%b):a;
}
inline void swap(int &a,int &b)
{
	int c=a;a=b,b=c;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(p1),read(p2),read(k);
		if(k==1){puts("REBEL");continue;}
		t=gcd(p1,p2),p1/=t,p2/=t;
		if(p1>p2)swap(p1,p2);
		if(int((p2-2)/p1)+1>=k)puts("REBEL");
		else puts("OBEY");
	}
	return 0;
}