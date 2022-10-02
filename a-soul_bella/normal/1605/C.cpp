#include <bits/stdc++.h>
using namespace std;
inline bool check(string s)
{
	int b=0,c=0;
	for(auto t:s)
	{
		if(t=='a') --b,--c;
		if(t=='b') ++b;
		if(t=='c') ++c;
	}
	return b<0&&c<0;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		int n;
		cin >> n >> s;
		s=' '+s;
		int ans=-1;
		for(int i=2;i<=11;i++)
		{
			for(int j=1;j+i-1<=n;j++)
			{
				if(check(s.substr(j,i)))
				{
					ans=i;
					break;
				}
			}
			if(ans!=-1) break;
		}
		cout << ans << "\n";
	}
	return 0;
}