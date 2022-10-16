#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,last,x;
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	last=1;
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&x);
		if(x-last>=0 && x-last<n-last+x)
			ans+=x-last;
		else ans+=n-last+x;
		last=x;
	}
	cout<<ans<<endl;
	return 0;
}