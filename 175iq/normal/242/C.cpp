#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;
int dir[][2]={0,1,0,-1,1,0,-1,0,1,-1,1,1,-1,1,-1,-1};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x0,y0,x1,y1;
	cin>>x0>>y0>>x1>>y1;

	int n,ans=-1;
	cin>>n;
	int r,a,b;

	set <pair<int,int> > S;
	map<pair<int, int>, int> level;
    set <pair<int,int> >:: iterator it;
	for (int i = 0; i < n; ++i)
	{
		cin>>r>>a>>b;
		for (int i = a; i <=b ; ++i)
		{
			S.insert(make_pair(r,i));
		}
	}

	queue<pair<int,int> > Q;

	Q.push(make_pair(x0,y0));
	level[make_pair(x0,y0)]=0;


	pair<int,int> temp;
	int x,y;
	while(!Q.empty())
	{
		temp=Q.front();
		Q.pop();
		if(temp.first==x1 && temp.second==y1)
		{
			ans=level[make_pair(x1,y1)];
			break;
		}
		else
		{
			for (int i = 0; i < 8; ++i)
			{
				x=temp.first+dir[i][0];
				y=temp.second+dir[i][1];
				it=S.find(make_pair(x,y));
				if(it!=S.end())
				{
					Q.push(make_pair(x,y));
					level[make_pair(x,y)]=level[temp]+1;
					S.erase(it);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}