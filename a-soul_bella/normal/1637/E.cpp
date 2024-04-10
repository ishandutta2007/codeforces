#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> s[300005];
map <signed,signed> mp;
int a[300005],cnt[300005],A[300005];
vector <int> S;
set <pair<int,int> > e;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		mp.clear();
		int n,m,qwq=0;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			A[i]=a[i];
			if(!mp[a[i]]) mp[a[i]]=++qwq,cnt[qwq]=0;
			a[i]=mp[a[i]];
		}
		for(int i=1;i<=n;i++) ++cnt[a[i]],s[i].clear(); 
		for(int i=1;i<=n;i++)
			s[cnt[a[i]]].push_back(A[i]);
		S.clear();
		for(int i=1;i<=n;i++)
		{
			if(s[i].size())
			{
				S.push_back(i),sort(s[i].begin(),s[i].end()),reverse(s[i].begin(),s[i].end());
				vector <int> v;
				v.push_back(s[i][0]);
				for(int j=1;j<s[i].size();j++)
					if(s[i][j]!=s[i][j-1]) v.push_back(s[i][j]);
				swap(v,s[i]);
			}
		}
		e.clear();
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin >> u >> v;
			e.insert({min(u,v),max(u,v)});
		}
		int ans=0;
		for(int I=0;I<S.size();I++)
		{
			for(int J=I;J<S.size();J++)
			{
				int i=S[I],j=S[J];
				int now=s[j].size();
				for(int k=0;k<s[i].size();k++)
				{
					if(k&&s[i][k]==s[i][k-1]) continue;
					for(int l=0;l<now;l++)
					{
						if(s[i][k]==s[j][l]) continue;
						if(e.find({min(s[i][k],s[j][l]),max(s[i][k],s[j][l])})==e.end())
						{
							ans=max(ans,(i+j)*(s[i][k]+s[j][l]));
							now=l;
							break;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}