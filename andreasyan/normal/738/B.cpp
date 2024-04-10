#include <iostream>
using namespace std;

const int N=1003;
int a[N][N],n,m,k;
bool l,r;
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>a[i][j];
	for(i=0;i<n;i++)
	{
		l=false;
		r=false;
		for(j=0;j<m;j++)
		{
			if(a[i][j]==1)
				l=true;
			if(!a[i][j] && l)
				k++;
		}
		for(j=m-1;j>=0;j--)
		{
			if(a[i][j]==1)
				r=true;
			if(!a[i][j] && r)
				k++;
		}
	}
	l=false;
	r=false;
	for(j=0;j<m;j++)
	{
		l=false;
		r=false;
		for(i=0;i<n;i++)
		{
			if(a[i][j]==1)
				r=true;
			if(!a[i][j] && r)
				k++;
		}
		for(i=n-1;i>=0;i--)
		{
			if(a[i][j]==1)
				l=true;
			if(!a[i][j] && l)
				k++;
		}
	}
	cout<<k<<endl;
	return 0;
}