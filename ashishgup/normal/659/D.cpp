#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, ans=0;
int x[N], y[N];
vector<char> v;
set<pair<char, char> > s;

int32_t main()
{
	IOS;
	s.insert({'U', 'L'});
	s.insert({'L', 'D'});
	s.insert({'D', 'R'});
	s.insert({'R', 'U'});
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		if(i>=2)
		{
			int xdiff=x[i]-x[i-1];
			if(xdiff>0)
				v.push_back('R');
			else if(xdiff<0)
				v.push_back('L');
			int ydiff=y[i]-y[i-1];
			if(ydiff>0)
				v.push_back('U');
			else if(ydiff<0)
				v.push_back('D');
		}
	}
	for(int i=0;i+1<v.size();i++)
	{
		if(s.find({v[i], v[i+1]})!=s.end())
			ans++;
	}
	cout<<ans;
	return 0;
}