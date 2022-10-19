#include<cstdio>
#define LL long long
int n,num,ans_t,Test_num;
LL W,sum;
int ans[200002];
LL w[200002];
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
		read(n),read(W),num=sum=ans_t=0;
		for(int i=1;i<=n;++i)read(w[i]);
		for(int i=1;i<=n;++i)if(w[i]>=(W+1)/2 && w[i]<=W){num=i;break;}
		if(num){printf("1\n%d\n",num);continue;}
		for(int i=1;i<=n;++i)if(w[i]<(W+1)/2)
		{
			sum+=w[i],ans[++ans_t]=i;
			if(sum>=(W+1)/2)break;
		}
		if(sum<(W+1)/2)puts("-1");
		else {printf("%d\n",ans_t);for(int i=1;i<=ans_t;++i)printf("%d%c",ans[i],i==ans_t? '\n':' ');}
	}
	return 0;
}