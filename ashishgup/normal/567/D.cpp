#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n, k, a, m;
int v[N];
bool mark[N];

int check(int idx)
{
	memset(mark, 0, sizeof(mark));
	for(int i=1;i<=idx;i++)
		mark[v[i]]=1;
	vector<int> s;
	for(int i=1;i<=n;i++)
		if(mark[i])
			s.push_back(i);
	int prev=0;
	int cnt=0;
	for(auto &it:s)
	{
		int cur=it;
		int diff=cur-1-prev;
		cnt+=(diff+1)/(a+1);
		prev=cur;
		if(cnt>=k)
			return 0;
	}
	cnt+=(n-prev+1)/(a+1);
	return cnt<k;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>k>>a;
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>v[i];
	int ans=binsearch(1, m);
	if(check(ans))
		cout<<ans;
	else
		cout<<"-1";
	return 0;
}