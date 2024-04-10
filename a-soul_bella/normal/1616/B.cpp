#include <bits/stdc++.h>
using namespace std;
int main() {
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
		if(s[1]==s[2])
			cout << s[1] << s[1] << "\n";
		else
		{
			int pos=0;
			string ans;
			ans+=s[1];
			for(int i=2;i<=n;i++)
			{
				if(s[i] > s[i - 1]) break;
				ans+=s[i];
			}
			cout << ans;
			reverse(ans.begin(),ans.end());
			cout << ans;
			cout << "\n";
		}
	}
	return 0;
}