#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define x first
#define y second

const int N=1e5+5;

int n, store;
pair<int, int> v[N];
set<int> s;

int makeline(int i, int j)
{
	int xdiff=v[j].x-v[i].x;
	int ydiff=v[j].y-v[i].y;
	vector<int> v1;
	for(int k=2;k<=n;k++)
	{
		if(s.find(k)!=s.end())
			continue;
		int left=xdiff * (v[k].y - v[i].y);
		int right=ydiff * (v[k].x - v[i].x);
		if(left!=right)
			v1.push_back(k);
	}	
	return (v1.size()==0);
}

void makeline2(int i, int j)
{
	s.clear();
	int xdiff=v[j].x-v[i].x;
	int ydiff=v[j].y-v[i].y;
	vector<int> v1;
	for(int k=1;k<=n;k++)
	{
		int left=xdiff * (v[k].y - v[i].y);
		int right=ydiff * (v[k].x - v[i].x);
		if(left!=right)
			v1.push_back(k);
		else
			s.insert(k);
	}	
	if(v1.size()<=2)
	{
		cout<<"YES";
		exit(0);
	}
	if(makeline(v1[0], v1[1]))
	{
		cout<<"YES";
		exit(0);
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	if(n<=4)
	{
		cout<<"YES";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>v[i].first>>v[i].second;
	}
	makeline2(1, 2);
	makeline2(1, 3);
	makeline2(2, 3);
	cout<<"NO";
	return 0;
}