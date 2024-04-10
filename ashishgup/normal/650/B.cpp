#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n, a, b, t, ans=0;
int cost[N], c1[N], c2[N];
string s;

void go_right()
{
	int cur=0, curans=0;
	for(int i=0;i<n;i++)
	{
		cur+=cost[i];
		if(cur>t)
			break;
		curans=max(curans, i+1);
		cur+=a;
	}
	ans=max(ans, curans);
}

void left_right()
{
	vector<int> v;
	int cur=0;
	v.push_back(cur);
	for(int i=1;i<n;i++)
	{
		cur+=(a+cost[i]);
		v.push_back(cur);
	}
	cur=0;
	int cnt=0;
	for(int i=n;i>0;i--)
	{
		cur+=cost[i%n];
		if(cur + a*cnt<=t)
		{
			auto it=upper_bound(v.begin(), v.end(), t-cur-a*cnt) - v.begin() - 1;
			ans=max(ans, cnt+1+it);
		}
		else
			break;
		cnt++;
		cur+=a;
	}
}

int32_t main()
{
	IOS;
	cin>>n>>a>>b>>t>>s;
	for(int i=0;i<n;i++)
		cost[i]=(s[i]=='w'?(b+1):1);
	go_right();
	reverse(cost+1, cost+n);
	go_right();
	reverse(cost+1, cost+n);
	left_right();
	reverse(cost+1, cost+n);
	left_right();
	ans=min(n, ans);
	cout<<ans;
	return 0;
}