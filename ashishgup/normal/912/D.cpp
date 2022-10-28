#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, m, r, k;
set<pair<int, int> > vis;
map<pair<int, int>, pair<int, int> > store;
priority_queue<pair<int, pair<int, int> > , vector<pair<int, pair<int, int> > > > pq;

int getrow(int x)
{
	return min(x, min(n-x+1, min(r, n-r+1)));
}	

int getcol(int y)
{
	return min(y, min(m-y+1, min(r, m-r+1)));
}

void insert(int x, int y)
{
	pair<int, int> p={x, y};
	int rowcontrib=getrow(x);
	int colcontrib=getcol(y);
	store[p]={getrow(x), getcol(y)};
	vis.insert(p);
	pq.push(make_pair(rowcontrib*colcontrib, p));
}

void addneighbours(int x, int y, int r, int c)
{
	for(int dx=-1;dx<=1;dx++)
	{
		for(int dy=-1;dy<=1;dy++)
		{
			int newx=x+dx;
			int newy=y+dy;
			pair<int, int> cur={newx, newy};
			if(vis.find(cur)!=vis.end())
			{
				continue;
			}
			int rowcontrib=getrow(newx);
			int colcontrib=getcol(newy);
			pq.push(make_pair(rowcontrib*colcontrib, cur));
			vis.insert(cur);
			pair<int, int> cur2={rowcontrib, colcontrib};
			store[cur]=cur2;
		}
	}
}

int32_t main()
{
    IOS;
   	cin>>n>>m>>r>>k;
	int nosq=1;
	int lensq=1;
	int ans=0;
	if(n%2 && m%2)
	{
		int x=(n+1)/2;
		int y=(m+1)/2;
		insert(x, y);
	}
	else if(n%2 != m%2)
	{
		if(n%2)
			swap(n, m);
		for(int x=(n+1)/2;x<=(n+1)/2+1;x++)
		{
			int y=(m+1)/2;
			insert(x, y);
		}
	}
	else
	{
		for(int x=(n+1)/2;x<=(n+1)/2+1;x++)
		{
			for(int y=(m+1)/2;y<=(m+1)/2+1;y++)
			{
				insert(x, y);
			}
		}
	}
	while(k>0)
	{
		pair<int, pair<int, int> > p=pq.top();
		pq.pop();
		k--;
		pair<int, int> q=store[p.second];
		ans+=p.first;
		addneighbours(p.second.first, p.second.second, q.first, q.second);
	}
	long double finans=ans;
	finans/=(n-r+1);
	finans/=(m-r+1);
	cout<<fixed<<setprecision(12)<<finans;
    return 0;
}