#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

string s;
int n;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s >> n;
		int sum = 0;
		for(auto &it:s)
			sum += (it - '0');
		if(sum >= n)
		{
			string ans = s;
			for(int i = 1; i <= n - 1; i++)
			{
				string cur = "";
				for(int j = 0; j < ans.size(); j++)
				{
					if(ans[j] >= '1')
					{
						ans[j]--;
						cur = '1';
						for(int k = j + 1; k < ans.size(); k++)
							cur += '0';
						break;
					}
				}
				cout << cur << " ";
			}
			int value = 0;
			for(auto &it:ans)
				value = (value * 10 + it - '0');
			cout << value << endl;
		}
		else
		{
			vector<int> cur(s.size(), 0);
			reverse(s.begin(), s.end());
			int sz = s.size();
			for(int i = 0; i < sz; i++)
				cur[i] = s[i] - '0';
			int reduce = n - sum;
			while(reduce > 0)
			{
				for(int i = 1; i < sz; i++)
				{
					int take = min((reduce + 9) / 10, cur[i]);
					if(take > 0)
					{
						cur[i]--;
						cur[i - 1] += 10;
						reduce -= 9;
						break;
					}
				}
			}
			for(int i = 1; i <= n - 1; i++)
			{
				int value = 0;
				for(int j = 0; j < cur.size(); j++)
				{
					if(cur[j] >= 1)
					{
						cur[j]--;
						value = 1;
						for(int k = j - 1; k >= 0; k--)
							value *= 10;
						break;
					}
				}
				cout << value << " ";
			}
			int value = 0;
			for(int i = cur.size() - 1; i >= 0; i--)
				value = (value * 10 + cur[i]);
			cout << value << endl;
		}
	}
	return 0;
}