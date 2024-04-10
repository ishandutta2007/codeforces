#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, m;
string s;
int pref[N];
 
void precompute()
{
	for(int i = 0; i + 1 < n; i++)
	{
		if(s[i] == s[i + 1])
			pref[i + 1]++;
	}
	for(int i = 1; i <= n; i++)
		pref[i] += pref[i - 1]
;}
 
int32_t main()
{
	IOS;
	cin >> s;
	n = s.size();
	precompute();
	cin >> m;
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		int ans = pref[r - 1] - pref[l - 1];
		cout << ans << endl;
	}
	return 0;
}