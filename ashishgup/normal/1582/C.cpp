#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;
string s;

int work(char ch)
{
	string str = s;
	string withoutChar = "";
	vector<int> idx;
	idx.push_back(-1);
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == ch)
			continue;
		withoutChar += s[i];
		idx.push_back(i);
	}
	idx.push_back(n);
	string rev = withoutChar;
	reverse(rev.begin(), rev.end());
	if(withoutChar != rev)
		return 1e9;
	int ans = n - idx.size() + 2;
	for(int i = 0, j = idx.size() - 1; i < j; i++, j--)
	{
		if(i == j - 1)
		{
			ans -= (idx[j] - idx[i] - 1);
			break;
		}
		int diff1 = idx[i + 1] - idx[i];
		int diff2 = idx[j] - idx[j - 1];
		ans -= 2 * (max(0LL, min(diff1, diff2) - 1));
	}
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		int ans = 1e9;
		for(char ch = 'a'; ch <= 'z'; ch++)
			ans = min(ans, work(ch));
		if(ans == 1e9)
			ans = -1;
		cout << ans << endl;
	}
	return 0;
}