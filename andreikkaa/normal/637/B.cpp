#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<cmath>
#include<bitset>
#include<cassert>
#include<queue>
#include<stack>
#include<deque>
#include<cassert>
using namespace std;
const int MAXN = 200 * 1000 + 7;
string s[MAXN];
map<string, int>pos;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;	
	int go = 1;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		pos[s] = go;
		go++;
	}
	vector<pair<int, string> >ans;
	for (auto x : pos)
	{
		ans.push_back(make_pair(x.second, x.first));
	}
	sort(ans.rbegin(), ans.rend());
	for (int i = 0; i < (int)ans.size(); i++)
	{
		cout << ans[i].second << '\n';
	}
}