#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k;
bool z;
char a[101],b[101];
int c[101];
int main()
{
	int i,j;
	cin>>n;
	cin>>a;
	for(i=0;i<n;i++)
		b[i]=a[i];
	for(i=2;i<n;i++)
	{
		if(a[i]=='o' && a[i-1]=='g' && a[i-2]=='o')
		{
			if(b[i]!='*' && b[i-1]!='*' && b[i-2]!='*')
				k++;
			b[i]='*';
			b[i-1]='*';
			b[i-2]='*';
			c[i]=k;
			c[i-1]=k;
			c[i-2]=k;
		}
	}
	for(i=0;i<n;i++)
	{
		if(b[i]=='*')
		{
			if(i-1==-1 || c[i]!=c[i-1])
			{
				cout<<"***";
				z=true;
			}
			continue;
		}
		cout<<b[i];
		z=false;
	}
	cout<<endl;
	return 0;
}