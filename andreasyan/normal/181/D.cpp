#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const long long N=100003,M=1000000007;

long long n,m,k;
char a[N],b[N],c[N];
long long L,V;
long long l[N],v[N];
int main()
{
	long long i,j;
	cin>>a>>b>>m;
	n=strlen(a);
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			c[(j+i)%n]=a[j];
		}
		bool z=true;
		for(j=0;j<n;++j)
		{
			if(b[j]!=c[j])
			{
				z=false;
				break;
			}
		}
		if(z)
			++L;
		else
			++V;
	}
	bool z=true;
	for(i=0;i<n;++i)
	{
		if(a[i]!=b[i])
		{
			z=false;
			break;
		}
	}
	if(z)
		l[0]=1;
	else
		v[0]=1;
	for(i=1;i<=m;++i)
	{
		l[i]=((l[i-1]*(L-1))%M+(v[i-1]*L)%M)%M;
		v[i]=((l[i-1]*V)%M+(v[i-1]*(V-1))%M)%M;
	}
	cout<<l[m]<<endl;
//	system("pause");
	return 0;
}