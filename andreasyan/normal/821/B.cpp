#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

long long n,m,k,b,x,y,ans;
int main()
{
	cin>>m>>b;
	x=m;
	while((-(x/m)+b)>=0)
	{
		y=(-(x/m)+b);
		ans=max(ans,((x*(x+1))/2)*(y+1)+((y*(y+1))/2)*(x+1));
		x+=m;
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}