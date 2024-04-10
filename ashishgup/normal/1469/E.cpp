#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 1e6 + 5;

int n, k;
int pref[N];
string s;

bool check(string &cur, int left)
{
	set<int> st;
	for(int i = 0; i + k - 1 < n; i++)
	{
		int off = 0;
		if(k >= 21)
		{
			if(pref[i + k - 1 - 20 + 1] - pref[i] >= 1)
				continue;
			off = k - 20;
		}
		bool skip = 0;
		for(int j = 0; j < cur.size(); j++)
			if(cur[j] == s[i + off + j])
				skip = 1;
		if(skip)
			continue;
		int val = 0;
		for(int j = cur.size(); i + off + j <= i + k - 1; j++)
			val = val * 2 + s[i + off + j] - '0';
		st.insert(val);
	}
	if(st.size() == left)
		return 0;
	return 1;
}

bool check2(string &cur)
{
	for(int i = 0; i + k - 1 < n; i++)
	{
		int off = 0;
		if(k >= 21)
		{
			if(pref[i + k - 1 - 20 + 1] - pref[i] >= 1)
				continue;
			off = k - 20;
		}
		bool skip = 0;
		for(int j = 0; j < cur.size(); j++)
			if(cur[j] == s[i + off + j])
				skip = 1;
		if(skip)
			continue;
		return 0;
	}
	return 1;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		cin >> s;
		string ans = "";
		for(int i = 0; i < n; i++)
			pref[i + 1] = (s[i] == '0') + pref[i];
		int left = (1 << min(20, k));
		int take = min(20, k);
		while(ans.size() < take)
		{
			string nw = ans + '0';
			if(nw.size() < k && check(nw, left / 2))
				ans += '0';
			else if(nw.size() == k && check2(nw))
				ans += '0';
			else
				ans += '1';
			left /= 2;
		}
		if(check2(ans))
		{
			cout << "YES" << endl;
			for(int i = 0; i + 20 < k; i++)
				cout << "0";
			cout << ans << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}