#include<cstdio>
#include<cstring>
#define inf 200000
int len,ans,Test_num;
int p[3],la[200002];
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
		p[0]=p[1]=p[2]=-1,scanf("%s",s),len=strlen(s);
		for(int i=0;i<len;++i)
			la[i]=p[s[i]-'1'],p[s[i]-'1']=i;
		if(p[0]<0 || p[1]<0 || p[2]<0)puts("0");
		else
		{
			ans=inf;
			while(p[0]>=0 && p[1]>=0 && p[2]>=0)
			{
				if(p[0]<p[1])
				{
					if(p[1]<p[2])ans=min(ans,p[2]-p[0]),p[2]=la[p[2]];
					else if(p[0]<p[2])ans=min(ans,p[1]-p[0]),p[1]=la[p[1]];
					else ans=min(ans,p[1]-p[2]),p[1]=la[p[1]];
				}
				else
				{
					if(p[0]<p[2])ans=min(ans,p[2]-p[1]),p[2]=la[p[2]];
					else if(p[1]<p[2])ans=min(ans,p[0]-p[1]),p[0]=la[p[0]];
					else ans=min(ans,p[0]-p[2]),p[0]=la[p[0]];
				}
			}
			printf("%d\n",ans+1);
		}
	}
	return 0;
}