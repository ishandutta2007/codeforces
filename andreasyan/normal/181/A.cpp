#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int N=102;

int n,m;
char a[N][N];
vector<pair<int,int> > b;
pair<bool,bool> c[4];
int main()
{
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			cin>>a[i][j];
			if(a[i][j]=='*')
				b.push_back(make_pair(i,j));
		}
	}
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			if(i==j)
				continue;
			if(b[i].first==b[j].first)
			{
				c[i].first=true;
				c[j].first=true;
			}
			if(b[i].second==b[j].second)
			{
				c[i].second=true;
				c[j].second=true;
			}
		}
	}
	int x,y;
	for(i=0;i<3;++i)
	{
		if(!c[i].first)
			x=b[i].first;
		if(!c[i].second)
			y=b[i].second;
	}
	cout<<x<<' '<<y<<endl;
//	system("pause");
	return 0;
}