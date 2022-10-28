
 #include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
int a[N], prv[N], vis[N];

void work(int idx)
{
	if(vis[idx])
		return;
	vis[idx]=1;
	if(prv[idx])
	{
		ans=max(ans, a[idx]^a[prv[idx]]);
		work(prv[idx]);
	}
}

void process()
{
	memset(vis, 0, sizeof(vis));
	stack<int> st;
	for(int i=1;i<=n;i++)
	{
		while(st.size() && a[st.top()]<a[i])
			st.pop();
		if(st.size())
			prv[i]=st.top();
		st.push(i);
	}
	for(int i=1;i<=n;i++)
		work(i);
}		

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	process();
	reverse(a+1, a+n+1);
	process();
	cout<<ans;
	return 0;
}