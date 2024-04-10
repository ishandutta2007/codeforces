#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int f[26], f2[26];
 
int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(f, 0, sizeof(f));
		memset(f2, 0, sizeof(f2));
		string a, b;
		cin >> a >> b;
		for(auto &it:a)
			f[it - 'a']++;
		for(auto &it:b)
			f2[it - 'a']++;
		int flag = 0;
		for(int i = 0; i < 26; i++)
			flag |= (f[i] > 0 && f2[i] > 0);
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}