#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int n;
char a[11][11];
bool stg()
{
	int i,j,k,ii,jj;
	for(i=0;i<10;++i)
	{
		for(j=0;j<=10;++j)
		{
			if(a[i][j]=='X')
			{
				///////////////////////////////////
				n=0;
				for(k=i;k<=10;++k)
				{
					if(a[k][j]!='X')
					{
						break;
					}
					++n;
				}
				if(n>=5)
					return true;
				////////////////////////////////////
				n=0;
				for(k=j;k<10;++k)
				{
					if(a[i][k]!='X')
					{
						break;
					}
					++n;
				}
				if(n>=5)
					return true;
				//////////////////////////////////////
				n=0;
				for(ii=i,jj=j;ii<10 && jj<10;++ii,++jj)
				{
					if(a[ii][jj]!='X')
					{
						break;
					}
					++n;
				}
				if(n>=5)
					return true;
				////////////////////////////////////
				n=0;
				for(ii=i,jj=j;ii<10 && jj>=0;++ii,--jj)
				{
					if(a[ii][jj]!='X')
					{
						break;
					}
					++n;
				}
				if(n>=5)
					return true;
			}
		}
	}
	return false;
}
int main()
{
	int i,j,k;
	for(i=0;i<10;++i)
		cin>>a[i];
	for(i=0;i<10;++i)
	{
		for(j=0;j<10;++j)
		{
			if(a[i][j]=='.')
			{
				a[i][j]='X';
				if(stg())
				{
					cout<<"YES"<<endl;
					return 0;
				}
				a[i][j]='.';
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}