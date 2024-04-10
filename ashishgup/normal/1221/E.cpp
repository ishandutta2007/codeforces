#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int a, b;
string s;

bool inRange(int x, int l, int r)
{
	return x >= l && x <= r;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		cin >> s;
		vector<int> lens;
		for(int i = 0; i < s.size(); i++)
		{
			int j = i;
			while(j + 1 < s.size() && s[i] == s[j + 1])
				j++;
			if(s[i] == 'X')
			{
				i = j;
				continue;
			}
			lens.push_back(j - i + 1);
			i = j;
		}
		if(!lens.size())
		{
			cout << "NO" << endl;
			continue;
		}
		sort(lens.begin(), lens.end());
		int cnt = 0, cnt2 = 0;
		int both = 0;
		for(auto &it:lens)
		{
			cnt += (it >= b && it < a);
			cnt2 += (it >= 2 * b);
			both += (it >= a && it < (a + b));
		}
		if(cnt > 0 || cnt2 > 1)
		{
			cout << "NO" << endl;
			continue;
		}
		if(lens.back() < a + b)
		{
			if(both % 2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
		{
			int last = lens.back();
			int canWin = 0;
			for(int i = 0; i + a <= last; i++)
			{
				int leftLen = i, rightLen = last - i - a;
				if(inRange(leftLen, 2 * b, 1e9) || inRange(rightLen, 2 * b, 1e9))
					continue;
				if(inRange(leftLen, b, a - 1) || inRange(rightLen, b, a - 1))
					continue;
				int cur = both + 1;
				cur += leftLen >= a;
				cur += rightLen >= a;
				if(cur % 2)
					canWin = 1;
			}
			if(canWin)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}