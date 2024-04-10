#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 2e5 + 5;

int n, m;
int pref[8][N];
string s;

int32_t main()
{
	IOS;
	cin >> n >> m;
	cin >> s;
	string cur = "abc";
	int idx = 0;
	do
	{
		int curIdx = 0;
		for(int i = 1; i <= n; i++)
		{
			pref[idx][i] = pref[idx][i - 1] + (s[i - 1] != cur[curIdx]);
			curIdx = (curIdx + 1) % 3;
		}
		idx++;
	}while(next_permutation(cur.begin(), cur.end())); //string is of the form (abc)* or some permutation
	//Queries
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		int ans = (r - l + 1);
		for(int i = 0; i < 6; i++)
		{
			int curCost = pref[i][r] - pref[i][l - 1];
			ans = min(ans, curCost);
		}
		cout << ans << endl;
	}
	return 0;
}