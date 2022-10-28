#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

vector<pair<int, int> > g[N];

int32_t main()
{
	IOS;
	int n, m, k;
	cin>>n>>m>>k;
	int current=1, count=0;
	int curi=1, curj=1, offset=1;
	while(current<k)
	{
		count+=2;
		g[current].push_back({curi, curj});
		curj+=offset;
		if(curj==m+1)
		{
			curj=m;
			offset=-1;
			curi++;
		}
		else if(curj==0)
		{
			curj=1;
			offset=1;
			curi++;
		}
		g[current].push_back({curi, curj});
		curj+=offset;
		if(curj==m+1)
		{
			curj=m;
			offset=-1;
			curi++;
		}
		else if(curj==0)
		{
			curj=1;
			offset=1;
			curi++;
		}
		current++;
	}
	while(count!=(n*m))
	{
		count++;
		g[current].push_back({curi, curj});
		curj+=offset;
		if(curj==m+1)
		{
			curj=m;
			offset=-1;
			curi++;
		}
		else if(curj==0)
		{
			curj=1;
			offset=1;
			curi++;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cout<<g[i].size()<<" ";
		for(auto j:g[i])
		{
			cout<<j.first<<" "<<j.second<<" ";
		}
		cout<<endl;
	}
}