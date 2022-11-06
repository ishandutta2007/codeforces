//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,s,in[100009],x,y,cnt;
double ans;
int main()
{
	n=read(),s=read();
	for(int i=1;i<n;i++)
	{
		x=read(),y=read();
		in[x]++,in[y]++;
	}
	for(int i=1;i<=n;i++)
		if(in[i]==1)cnt++;
	ans=s*1.0/cnt*1.0*2.0;
	printf("%.12lf\n",ans);
	return 0;
}