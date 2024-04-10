#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n,m,l,pos,a[100009];
double res,k;
long long ans;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read(),m=read();pos=n;
		for(int i=1;i<=n;i++)a[i]=read();
		while(pos>0&&a[pos]==pos)pos--;
		res=1.0;
		if(pos==0)res=0.0;
		for(int i=1;i<=m;i++)
		{
			l=read();scanf("%lf",&k);
			if(l>=pos)
			{
				res=res*(1.0-k);
	//			printf("%.9lf\n",res);
			}
		}
		res=1.0-res;
		printf("%.9lf\n",res);
	}
	return 0;
}