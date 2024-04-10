#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define x first
#define y second

int distance(pair<int, int> &p1, pair<int, int> &p2)
{
	int xdiff=p1.x-p2.x;
	int ydiff=p1.y-p2.y;
	return (xdiff*xdiff + ydiff*ydiff);
}

int check(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3, pair<int, int> &p4)
{
	map<int, int> m;
	m[distance(p1, p2)]++;
	m[distance(p1, p3)]++;
	m[distance(p1, p4)]++;
	m[distance(p2, p3)]++;
	m[distance(p2, p4)]++;
	m[distance(p3, p4)]++;
	int len=m.begin() -> first;
	if(m[len]==4&&m[len*2]==2)
		return 1;
	return 0;
}

vector<pair<int, int> > get_loc(pair<int, int> &p1, pair<int, int> &p2)
{
	vector<pair<int, int> > store;
	pair<int, int> d={p1.x - p2.x, p1.y - p2.y};
	for(int i=1;i<=4;i++)
	{
		store.push_back({p2.x + d.x, p2.y + d.y});
		swap(d.x, d.y);
		d.first*=-1;
	}
	return store;
}

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    for(int z=1;z<=n;z++)
    {
    	pair<int, int> mo[5], re[5];
    	for(int i=1;i<=4;i++)
    	{
    		cin>>mo[i].x>>mo[i].y>>re[i].x>>re[i].y;
    	}
    	vector<pair<int, int> >  pt [5];
    	for(int i=1;i<=4;i++)
    	{
    		vector<pair<int, int> > pts=get_loc(mo[i], re[i]);
    		for(auto it:pts)
    			pt[i].push_back(it);
    	}
    	int ans=1000;
    	for(int a=0;a<=3;a++)
    	{
    		for(int b=0;b<=3;b++)
    		{
    			for(int c=0;c<=3;c++)
    			{
    				for(int d=0;d<=3;d++)
    				{
    					if(check(pt[1][a], pt[2][b], pt[3][c], pt[4][d]))
    					{
    						ans=min(ans, a+b+c+d);
    					}	
    				}
    			}
    		}
    	}
    	if(ans<1000)
    		cout<<ans<<endl;
    	else
    		cout<<"-1"<<endl;
    }
    return 0;
}