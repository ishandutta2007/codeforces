#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
char a[1000003],b[1000003];
int n,m,t1,t2;
int main()
{
	int i,j,ii=0,jj=0;
	bool z1=false,z2=false;
	scanf("%s",&a);
	scanf("%s",&b);
	n=strlen(a);
	m=strlen(b);
	for(i=0;i<n;++i)
	{
		if(a[i]!='0' && !z1)
		{
			ii=i;
			z1=true;
		}
	}
	for(i=0;i<m;i++)
	{
		if(b[i]!='0' && !z2)
		{
			jj=i;
			z2=true;
		}
	}
	if(!z1 && !z2)
	{
		cout<<'='<<endl;
//		system("pause");
		return 0;
	}
	if(z1 && !z2)
	{
		cout<<'>'<<endl;
		return 0;
	}
	if(!z1 && z2)
	{
		cout<<'<'<<endl;
		return 0;
	}
	if(n-ii>m-jj)
	{
		cout<<'>'<<endl;
		return 0;
	}
	if(n-ii<m-jj)
	{
		cout<<'<'<<endl;
		return 0;
	}
	for(i=ii,j=jj;i<=n,j<=m;i++,j++)
	{
		int x=a[i]-'0';
		int y=b[j]-'0';
		if(x>y)
		{
			cout<<'>'<<endl;
			return 0;
		}
		if(x<y)
		{
			cout<<'<'<<endl;
			return 0;
		}
	}
	cout<<'='<<endl;
	return 0;
}