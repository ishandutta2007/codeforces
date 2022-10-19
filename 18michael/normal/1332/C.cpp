#include<cstdio>
int n,k,ans,tmp,Test_num;
int tim[200002][26];
char s[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int min(int a,int b)
{
	return a<b? a:b;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		ans=0,read(n),read(k),scanf("%s",s);
		for(int i=0;i<=k/2;++i)
			for(int j=0;j<26;++j)
				tim[i][j]=0;
		for(int i=0;i<n;++i)
			++tim[min(i%k,k-1-i%k)][s[i]-'a'];
		for(int i=0;i<=k/2;++i)
		{
			tmp=tim[i][0];
			for(int j=1;j<26;++j)
				if(tim[i][j]>tmp)
					tmp=tim[i][j];
			ans+=tmp;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}