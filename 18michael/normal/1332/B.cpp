#include<cstdio>
#include<cstring>
int n,p_t,u_t,num_t,Test_num;
int p[12]={0,2,3,5,7,11,13,17,19,23,29,31},a[1002],c[1002],u1[12];
bool u[12];
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
		memset(c,0,sizeof(c));
		memset(u,0,sizeof(u));
		p_t=u_t=0,read(n);
		for(int i=1;i<=n;++i)
		{
			read(a[i]);
			for(int j=1;j<=11;++j)
				if(!(a[i]%p[j]))
				{
					c[i]=j;
					if(!u[j])++p_t;
					u[j]=1;
					break;
				}
		}
		for(int i=1;i<=11;++i)
			if(u[i])u1[i]=++u_t;
		printf("%d\n",p_t);
		for(int i=1;i<=n;++i)
			printf("%d%c",u1[c[i]],i==n? '\n':' ');
	}
	return 0;
}