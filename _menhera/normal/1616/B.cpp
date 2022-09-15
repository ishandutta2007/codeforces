#include<bits/stdc++.h>
using namespace std;

int main()
{
	auto rev = [&](string s){ reverse(s.begin(), s.end()); return s; };
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--)
	{
		int N; string s; cin >> N >> s;
		string ans = min(string(2, s[0]), s + rev(s));
		for(int i=1; i<N; ++i)
		{
			if(s[i-1] != s[i])
			{
				string t = s.substr(0, i);
				ans = min(ans, t+rev(t));
			}
			if(s[i-1] < s[i]) break;
		}
		cout << ans << '\n';
	}
}