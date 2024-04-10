#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int storewhite, storeblack;
int connected[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > white, black;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int c, s;
		cin>>c>>s;
		if(c)
			black.push({s, i});
		else
			white.push({s, i});
	}
	while(white.size() && black.size())
	{
		pair<int, int> p1=black.top();
		black.pop();
		pair<int, int> p2=white.top();
		white.pop();
		int w=min(p1.first, p2.first);
		p1.first-=w;
		p2.first-=w;
		if(p1.first!=0)
			storewhite=p2.second;
		else
			storeblack=p1.second;
		if(p1.first!=0)
			black.push(p1);
		else 
			white.push(p2);
		connected[p1.second]=1;
		connected[p2.second]=1;
		cout<<p1.second<<" "<<p2.second<<" "<<w<<endl;
	}
	while(white.size())
	{
		pair<int, int>  p=white.top();
		white.pop();
		if(connected[p.second])
			continue;
		cout<<storeblack<<" "<<p.second<<" "<<0<<endl;
	}
	while(black.size())
	{
		pair<int, int>  p=black.top();
		black.pop();
		if(connected[p.second])
			continue;
		cout<<storewhite<<" "<<p.second<<" "<<0<<endl;
	}
 	return 0;
}