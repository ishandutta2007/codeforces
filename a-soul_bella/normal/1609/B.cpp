#include <bits/stdc++.h>
using namespace std;
inline int cal(string s)
{
	int rtn=0;
	for(int i=2;i<s.size();i++)
	{
		if(s[i]=='c'&&s[i-1]=='b'&&s[i-2]=='a')
		{
			++rtn;
		}
	}
	return rtn;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,T;
	cin >> n >> T;
	string s;
	cin >> s;
	s="      "+s+"     ";
	int ans=cal(s);
	while(T--)
	{
		int pos;
		char c;
		cin >> pos >> c;
		pos+=5;
		ans-=cal(s.substr(pos-2,5));
		s[pos]=c;
		ans+=cal(s.substr(pos-2,5));
		cout << ans << "\n";
	}
	return 0;
}