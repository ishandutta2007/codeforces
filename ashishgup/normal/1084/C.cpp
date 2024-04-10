#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int MOD=1e9+7;

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	vector<int> v;
	char ch=s[0];
	int cnt=1;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]==ch)
			cnt++;
		else if(s[i]=='b')
		{
			if(ch=='a')
				v.push_back(cnt);
			cnt=1;
			ch=s[i];
		}
		else if(s[i]=='a')
		{
			ch=s[i];
			cnt=1;
		}
	}
	if(ch=='a')
		v.push_back(cnt);
	int ans=1;
	for(auto &it:v)
	{
		ans*=(it+1);
		ans%=MOD;
	}
	ans-=1;
	cout<<ans;
	return 0;
}