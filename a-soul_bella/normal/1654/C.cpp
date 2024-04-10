#include <bits/stdc++.h>
#define int long long
using namespace std;
priority_queue <int> q,p;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		while(!q.empty()) q.pop();
		while(!p.empty()) p.pop();
		int s=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			s+=x;
			p.push(x);
		}
		q.push(s);
		while(!p.empty())
		{
			int x=q.top();
			q.pop();
			if(x==p.top())
				p.pop();
			else if(x<p.top())
			{
				break;
			}
			else
			{
				q.push(x/2);
				q.push(x-x/2);
			}
		}
		if(p.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}