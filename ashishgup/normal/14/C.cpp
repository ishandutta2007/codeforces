#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define x first
#define y second

int hori=0, verti=0;
int x1[5], y1[5], x2[5], y2[5];
pair<int, int> a[5];
set<pair<int, int> > s;
map<pair<int, int>, int> m;

int check()
{
	if(a[1].x!=a[2].x)
		return 0;
	if(a[3].x!=a[4].x)
		return 0;
	if(a[2].y!=a[3].y)
		return 0;
	if(a[1].y!=a[4].y)
		return 0;
	return 1;
}

int32_t main()
{
    IOS;
   	for(int i=1;i<=4;i++)
   	{
   		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
   		s.insert({x1[i], y1[i]});
   		s.insert({x2[i], y2[i]});
   		if(x1[i]==x2[i] && y1[i]!=y2[i])
   			hori++;
   		if(y1[i]==y2[i] && x1[i]!=x2[i])
   			verti++;
   		m[{x1[i], y1[i]}]++;
   		m[{x2[i], y2[i]}]++;
   	}
   	if(s.size()!=4 || hori!=2 || verti!=2)
   	{
   		cout<<"NO";
   		return 0;
   	}
   	for(auto it:m)
   	{
   		if(it.second!=2)
   		{
   			cout<<"NO";
   			return 0;
   		}
   	}
   	int idx=1;
   	for(auto it:s)
   		a[idx++]=it;
   	sort(a+1, a+5);
   	swap(a[3], a[4]);
   	if(check())
   		cout<<"YES";
   	else
   		cout<<"NO";
    return 0;
}