#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int q;
int pref[26][N];
string s;

int check(int l, int r)
{
	if(r - l + 1 == 1)
		return 1;
	int m = l + (r - l) / 2;
	int cnt = 0;
	for(int i = 0; i < 26; i++)
	{
		int fA = pref[i][m] - pref[i][l - 1];
		int fB = pref[i][r] - pref[i][m];
		int totF = fA + fB;
		if(totF > 0)
			cnt++;
	}
	if(cnt > 2)
		return 1;
	if(s[l - 1] != s[r - 1])
		return 1;
	return 0;
}

int32_t main()
{
	IOS;
	cin >> s >> q;
	n = s.size();
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 26; j++)
			pref[j][i] = pref[j][i - 1];
		pref[s[i - 1] - 'a'][i]++;
	}
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		if(check(l, r))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}