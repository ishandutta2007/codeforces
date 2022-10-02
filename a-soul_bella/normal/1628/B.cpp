#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt3[150][150][150],cnt2[150][150],cnt1[150];
string s[100005];
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
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			cin >> s[i];
			if(s[i].size()==1) flag=1;
			else if(s[i].size()==2)
			{
				if(s[i][0]==s[i][1]) flag=1;
				else
				{
					++cnt2[s[i][0]][s[i][1]];
					if(cnt2[s[i][1]][s[i][0]])
					{
						flag=1;
					}
					for(int k='a';k<='z';k++)
					{
						if(cnt3[s[i][1]][s[i][0]][k])
						{
							flag=1;
						}
					}
				}
			}
			else
			{
				if(s[i][0]==s[i][2]) flag=1;
				else
				{
					++cnt3[s[i][0]][s[i][1]][s[i][2]];
					if(cnt3[s[i][2]][s[i][1]][s[i][0]]) flag=1;
					else
					{
						if(cnt2[s[i][2]][s[i][1]]) flag=1;
					}
				}
			}
		}
		if(flag) cout << "YES\n";
		else cout << "NO\n";
		for(int i=1;i<=n;i++)
		{
			if(s[i].size()==2) cnt2[s[i][0]][s[i][1]]=0;
			if(s[i].size()==3) cnt3[s[i][0]][s[i][1]][s[i][2]]=0;
		}
	}
	return 0;
}