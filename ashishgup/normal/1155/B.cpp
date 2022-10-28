#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
string s, cur = "";

int32_t main()
{
	IOS;
	cin >> n >> s;
	int moves = n - 11;
	moves /= 2;
	for(auto &it:s)
	{
		if(it == '8')
		{
			if(moves > 0)
				moves--;
			else
				cur += it;
		}
		else
			cur += it;
	}
	for(int i = 0; i < cur.size(); i++)
	{
		if(cur[i] == '8')
		{
			int rem = cur.size() - 1 - i;
			int taken = i - 1;
			int have_to_take = max(0LL, moves - taken);
			if(rem >= 10 + have_to_take)
			{
				cout << "YES";
				return 0;
			}
			break;
		}
	}
	cout << "NO";
	return 0;
}