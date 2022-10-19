#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m;
char a[102];
int main()
{
	int i,j,k,ii;
	int p,q;
	cin>>n>>p>>q>>a;
	for(i=0;i<=n;++i)
	{
		for(j=0;j<=n;++j)
		{
			if(i*p+j*q==n)
			{
				k=0;
				cout<<i+j<<endl;
				while(1)
				{
					if(i)
					{
						--i;
						for(ii=0;ii<p;++ii,++k)
						{
							cout<<a[k];
						}
						cout<<endl;
						continue;
					}
					if(j)
					{
						--j;
						for(ii=0;ii<q;++ii,++k)
						{
							cout<<a[k];
						}
						cout<<endl;
						continue;
					}
					return 0;
				}
			}
		}
	}
	cout<<"-1"<<endl;
	return 0;
}