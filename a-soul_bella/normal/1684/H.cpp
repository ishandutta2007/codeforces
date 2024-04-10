#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int> > ans;
int vis[1000005];
inline void ins(int l,int r)
{
	for(int i=l;i<=r;i++) vis[i]=1;
	ans.push_back({l,r});
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		int n=s.size();
		for(int i=1;i<=n;i++) vis[i]=0;
		s=' '+s;
		int cnt=0;
		for(auto t:s) cnt+=t=='1';
		if(!cnt)
		{
			cout << "-1\n";
			continue;
		}
		ans.clear(); 
		if(cnt==5)
		{
			int flag=0;
			for(int i=5;i<=n;i++)
			{
				if(s[i-4]+s[i-3]+s[i-2]+s[i-1]+s[i]-'0'*5==5)
				{
					ins(i-4,i-1),flag=1;
					break;
				}
			}
			if(!flag)
			{
				for(int i=1;i<=n;i++)
				{
					if(s[i]=='1'&&s[i+1]!='1')
					{
						ins(i,i+2);
						break;
					}
				}
			}
		}
		else
		{
			int qwq=1;
			while(qwq<cnt) qwq<<=1;
			qwq-=cnt;
			int nw=0,L=1;
			for(int i=1;i<=n;i++)
			{
				if(qwq>=nw) qwq-=nw;
				else ins(L,i-1),L=i,nw=0;
				nw=nw*2+s[i]-'0';
			}
			ins(L,n);
		}
		for(int i=1;i<=n;i++)
			if(!vis[i]) ins(i,i);
		sort(ans.begin(),ans.end());
		cout << ans.size() << "\n";
		for(auto t:ans) cout << t.first << " " << t.second << "\n";
	}
	return 0;
}