#include<cstdio>
#include<cstring>
int n,Test_num;
bool ans;
int x[5002],cnt[5002];
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
		ans=0,memset(cnt,0,sizeof(cnt)),read(n);
		for(int i=1;i<=n;++i)
		{
			read(x[i]);
			if(!ans)
			{
				++cnt[x[i]];
				if(cnt[x[i]]>=3 || (cnt[x[i]]==2 && x[i]!=x[i-1]))ans=1;
			}
		}
		if(ans)puts("YES");
		else puts("NO");
	}
	return 0;
}