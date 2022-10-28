#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3+5;

int x;

int calc(int m)
{
	int n=m;
	int num=x - m*(m+1)*(2*m+1)/6;
	num/=(m*(m+1)/2);
	n+=num;
	if(n<=0)
		return -1;
	return n;
}

int check(int n, int m)
{
	if(n<=m)
		swap(n, m);
	int calc1=m*(m+1)*(2*m+1)/6;
	int calc2=(n-m)*m*(m+1)/2;
	int ans=calc1+calc2;
	if(ans==x)
		return 1;
	else
		return 0;
}

int32_t main()
{
	IOS;
	cin>>x;
	set<pair<int, int> > s;
	for(int i=1;i<=1e7;i++)
	{
		int n=calc(i);
		if(n==-1)
			return 0;
		if(check(n, i))
		{
			s.insert(make_pair(n, i));
			s.insert(make_pair(i, n));
		}
	}
	cout<<s.size()<<endl;
	for(auto it:s)
		cout<<it.first<<" "<<it.second<<endl;
	return 0;
}