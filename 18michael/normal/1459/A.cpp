#include<cstdio>
int n,t1,t2,Test_num;
char R[1002],B[1002];
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
		read(n),scanf("%s",R),scanf("%s",B),t1=t2=0;
		for(int i=0;i<n;++i)
		{
			if(R[i]<B[i])++t1;
			if(R[i]>B[i])++t2;
		}
		if(t1>t2)puts("BLUE");
		else if(t1<t2)puts("RED");
		else puts("EQUAL");
	}
	return 0;
}