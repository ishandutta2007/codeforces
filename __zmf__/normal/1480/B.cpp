#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
long long taxi,n,A,kk,B,a[100009],b[100009],flag,maxa;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		flag=0;
		A=read(),B=read();
		n=read();
		maxa=0;
		for(int i=1;i<=n;i++)a[i]=read(),maxa=max(maxa,a[i]);
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=1;i<=n;i++)
		{
			kk=(b[i]-1)/A+1;B=B-kk*a[i];
			//cout<<kk<<endl;
		}
		if(B+maxa>0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}