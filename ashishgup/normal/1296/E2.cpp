#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, mx = 0;
string s;
int mex[256], col[N];

int32_t main()
{
	IOS;
	cin >> n >> s;
	memset(mex, -1, sizeof(mex));
	for(int i = 0; i < n; i++)	
	{
		int cur = -1;
		for(char ch = s[i] + 1; ch <= 'z'; ch++)
			cur = max(cur, mex[ch]);
		cur++;
		mex[s[i]] = cur;
		col[i] = cur;
		mx = max(mx, cur + 1);
	}
	cout << mx << endl;
	for(int i = 0; i < n; i++)
		cout << col[i] + 1 << " ";
	return 0;
}