#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, p;
string s;
vector<int> a, b;

int work(vector<int> &v)
{
	if(!v.size())
		return 0;
	int goleft=abs(v[0]-p) + abs(v[v.size()-1] - v[0]);
	int goright=abs(v[v.size()-1]-p) + abs(v[v.size()-1] - v[0]);
	return min(goleft, goright);
}

int32_t main()
{
	IOS;
	cin>>n>>p>>s;
	p--;
	int ans=0;
	for(int i=0, j=n-1;i<j;i++, j--)
	{
		ans+=min(abs(s[i]-s[j]), 26 - abs(s[i]-s[j]));
		if(s[i]!=s[j])
		{
			a.push_back(i);
			b.push_back(j);
		}
	}
	reverse(b.begin(), b.end());
	ans+=min(work(a), work(b));
	cout<<ans;
}