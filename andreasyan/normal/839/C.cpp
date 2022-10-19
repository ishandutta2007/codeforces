#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;
const int N=100005;

vector<int> a[N];
int n;
long double ans;
void dfs(int x,int p,int d, long double shans)
{
	if(a[x].size()==1 && p!=-1)
	{
		ans+=(shans*d);
		return;
	}
	for(int i=0;i<a[x].size();++i)
	{
		int h=a[x][i];
		if(h==p)continue;
		if(p!=-1)
			dfs(h,x,d+1,shans/(a[x].size()-1));
		else
			dfs(h,x,d+1,shans/a[x].size());
	}
}
int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(15);
	scanf("%d",&n);
	for(int i=0;i<n-1;++i)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,-1,0,1);
	cout<<ans<<endl;
//	system("pause");
	return 0;
}