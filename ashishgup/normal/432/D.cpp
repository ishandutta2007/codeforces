#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

vector<int> z_function(string s)
{
	int n=s.size();
	vector<int> z(n);
	for(int i=1,l=0,r=0;i<n;i++)
	{
		if(i<=r)
			z[i]=min(r-i+1, z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])
			z[i]++;
		if(i+z[i]-1>r)
			l=i, r=i+z[i]-1;
	}
	return z;
}

int n, len=0;
int bit[1000005];
string s;
vector<int> z;
map<int, int> m;

void update(int idx, int val)
{
	if(idx==0)
		return;
	while(idx<=n)
	{
		bit[idx]+=val;
		idx+=(idx&-idx);
	}
}

int pref(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx-=(idx&-idx);
	}	
	return ans;
}

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	z=z_function(s);
	for(int i=1;i<n;i++)
		update(z[i], 1);
	for(int i=n-1;i>=1;i--)
	{
		if(z[i]!=(n-i))
			continue;
		m[z[i]]+=(pref(n) - pref(z[i]-1) + 1);
	}
	m[n]++;
	cout<<m.size()<<endl;
	for(auto it:m)
		cout<<it.first<<" "<<it.second<<endl;
	return 0;
}