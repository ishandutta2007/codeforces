#include <iostream>
#include <cstdio>
using namespace std;
const int N=55;

int n,m;
int a[N][N];
int main()
{
	int i,j,k,ii,jj;
	cin>>n;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(a[i][j]==1)
				continue;
			bool z=false;
			for(ii=0;ii<n;++ii)
			{
				for(jj=0;jj<n;++jj)
				{
					if(a[i][j]==a[i][jj]+a[ii][j])
						z=true;
				}
			}
			if(z==false)
			{
				cout<<"No"<<endl;
//				system("pause");
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
//	system("pause");
	return 0;
}