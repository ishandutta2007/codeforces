#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	unordered_map <int,int> M;
	M[2]=2;
	M[3]=3;
	M[4]=322;
	M[5]=5;
	M[6]=53;
	M[7]=7;
	M[8]=7222;
	M[9]=7332;
	
	string ans ;

	for (int i = 0; i < s.size(); ++i)
	{
		if( (s[i]!='0') && (s[i]!='1') )
		{
			ans += to_string(M[(s[i]-'0')]);
		}
	}

	sort(ans.begin(),ans.end(),greater<int>());
	cout<<ans;
	return 0;
}