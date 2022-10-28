#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int ans=0;
int k, p;

void work(int j)
{
	string cur=to_string(j);
	string rev=cur;
	reverse(rev.begin(), rev.end());
	cur+=rev;
	int sz=cur.size();
	int pw=1;
	for(int i=sz-1;i>=0;i--)
	{
		int cur1=cur[i]-'0';
		cur1*=pw;
		pw*=10;
		pw%=p;
		cur1%=p;
		ans+=cur1;
		ans%=p;
	}
}

int32_t main()
{
	IOS;
	cin>>k>>p;
	for(int i=1;i<=k;i++)
	{
		work(i);
	}
	cout<<ans;
	return 0;
}