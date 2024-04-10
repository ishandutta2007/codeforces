#include <bits/stdc++.h>
#define int long long
using namespace std;
int ban[205];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string s,t;
		cin >> s >> t;
		int now=s.size()-1;
		memset(ban,0,sizeof ban);
		int ans=1;
		for(int i=t.size()-1;i>=0;i--)
		{
			while(now>0&&t[i]!=s[now]) ban[s[now]]=1,--now;
			if(now<0||t[i]!=s[now])
			{
				ans=0;
				break;
			}
			if(ban[t[i]])
			{
				ans=0;
				break;
			}
			--now;
		}
		if(ans)
		{
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}