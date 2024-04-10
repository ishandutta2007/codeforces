#include<cstdio>
int n,t=0;
char l[1000002],r[1000002];
inline bool check()
{
	for(int i=0;i<n;++i)if((t=(t<<1)+r[i]-l[i])>=2)return 1;
	return 0;
}
int main()
{
	scanf("%d%s%s",&n,l,r);
	for(int i=0;i<n;++i)
		if(r[i]=='1')
		{
			if(l[i]=='0')
			{
				for(int j=0;j<n;++j)putchar('1');
				return 0;
			}
			break;
		}
	if(!(r[n-1]&1) && check())r[n-1]^=1;
	return 0&printf("%s",r);
}