#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
const int N=10005;

int n,m;
char a[N],b[N],c[N];
int main()
{
	int i,j,k,l,r,x;
	cin>>a;
	cin>>m;
	n=strlen(a);
	for(k=0;k<m;++k)
	{
		cin>>l>>r>>x;
		l--;
		r--;
		for(i=l,j=0;i<=r;++i,++j)
			b[j]=a[i];
		for(i=0;i<=(r-l);++i)
			c[(i+x)%(r-l+1)]=b[i];
		for(i=l,j=0;i<=r;++i,++j)
			a[i]=c[j];
	}
	cout<<a<<endl;
	return 0;
}