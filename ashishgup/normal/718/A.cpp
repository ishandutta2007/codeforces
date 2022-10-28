#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '.')
		{
			bool mark = 0;
			for(int j = i + 1; j < s.size(); j++)
			{
				if(s[j] >= '5')
				{
					for(int k = j; k < s.size(); k++)
					{
						s[k] = '0';
						if(j == i + 1)
							mark = 1;
					}
					for(int k = j - 1; k > i && t > 0; k--)
					{
						s[k]++;
						t--;
						if(k + 1 < s.size())
							s[k + 1] = '0';
						if(s[k] < '5')
							break;
					}
					break;
				}
			}
			if(mark || (s[i + 1] >= '5' && t > 0))
			{
				s[i + 1] = '0';
				for(int j = i - 1; j >= 0; j--)
				{
					s[j]++;
					if(s[j] <= '9')
						break;
					else
						s[j] = '0';
				}
				if(s[0] == '0')
					s = "1" + s;
			}
		}
	}
	while(s.back() == '0')
		s.pop_back();
	if(s.back() == '.')
		s.pop_back();
	cout << s;
	return 0;
}