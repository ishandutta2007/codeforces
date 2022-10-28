#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		string s;
		cin >> n >> k >> s;
		set<int> idx;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '0')
				idx.insert(i);
		}
		int cur = 0;
		for(int i = 0; i < n;)
		{
			if(idx.find(i) == idx.end() && s[i] == '0')
			{
				i++;
				continue;
			}
			if(idx.size())
			{
				int nxt = *idx.begin();
				if(nxt - cur <= k)
				{
					k -= (nxt - cur);
					cout << 0;
					idx.erase(nxt);
					cur++;
				}
				else
				{
					cout << s[i];
					i++;
					cur++;
				}
			}
			else
			{
				cout << s[i];
				i++;
				cur++;
			}
		}
		cout << endl;
	}
	return 0;
}