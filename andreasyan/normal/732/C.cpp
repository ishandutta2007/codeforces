#include <iostream>
#include <algorithm>
using namespace std;

struct ban
{
	int x,y,z;
};
unsigned long long n,m,k,x[10],a,b,c,z[3],ya,yb,yc;
ban y[10]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,1},{1,1,0}};
int main()
{
	int i,j;
	cin>>a>>b>>c;
	n=a+b+c;
	///////////////////
	z[0]=a;
	z[1]=b;
	z[2]=c;
	sort(z,z+3);
	m=z[2];
	///////////////////
	for(i=0;i<9;i++)
	{
		ya=m-y[i].x;
		yb=m-y[i].y;
		yc=m-y[i].z;
		if(ya<a || yb<b || yc<c)
			x[i]=9999999999999999999LL;
		else
			x[i]=ya-a + yb-b + yc-c;
	}
	sort(x,x+9);
	cout<<x[0]<<endl;
	return 0;
}