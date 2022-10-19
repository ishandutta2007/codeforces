#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m;
int ans;
int main()
{
	int i,j,x,y,x0,y0;
	cin>>x>>y>>x0>>y0;
	if(max(x,x0)-min(x,x0)<max(y,y0)-min(y,y0))
	{
		cout<<max(y,y0)-min(y,y0)<<endl;
	}
	else
	{
		cout<<max(x,x0)-min(x,x0)<<endl;
	}
	return 0;
}