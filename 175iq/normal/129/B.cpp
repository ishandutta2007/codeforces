#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;

std::vector<int> adjlist[101];
std::vector<int> deg(101,0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin>>n>>m;
	int x,y;

	for (int i = 0; i < m; ++i)
	{
		cin>>x>>y;
		adjlist[x].push_back(y);
		adjlist[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}

	int number=0;
	bool mark=0;
	int count=0,temp;
	vector<int> vec;
	while(1)
	{
	    mark=0;
	    vec.clear();
		for (int i = 1; i <= n; ++i)
		{
			if(deg[i]==1)
			{
			    //cout<<"YADA "<<i<<endl;
				mark=1;
				deg[i]--;
				temp=adjlist[i][0];
				vec.push_back(temp);
				auto it=adjlist[temp].begin();
				for( ; it<adjlist[temp].end();it++)
				{
				    if(*it==i)
				    {
				        break;
				    }
				}
				adjlist[temp].erase(it);
			}
		}
		if(!mark)
		{
			break;
		}
		else
		{
		    for(int i=0;i<vec.size();i++)
		    {
		        deg[vec[i]]--;
		    }
			count++;
		}
	}
	cout<<count;
	return 0;
}