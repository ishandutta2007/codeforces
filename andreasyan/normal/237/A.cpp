#include <iostream>
using namespace std;

int a[100005],b[100005],n,m,k;
bool t;
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	a[0]=-1;
	b[0]=-1;
	k=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1] || b[i]!=b[i-1])
		{
			t=true;
			if(m+1>k)
				k+=m+1-k;
			m=0;
		}
		if(a[i]==a[i-1] && b[i]==b[i-1])
			m++;
	}
	if(m+1>k)
		k+=m+1-k;
	cout<<k<<endl;
	return 0;
}