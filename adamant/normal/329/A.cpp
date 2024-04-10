#include <bits/stdc++.h>

using namespace std;

signed main()
{
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++)
		cin >> s[i];
	bool ok = 1;
	for(int i = 0; i < n; i++)
		ok &= string::npos != s[i].find('.');
	if(ok)
	{
		for(int i = 0; i < n; i++)
			cout << i + 1 << ' ' << s[i].find('.') + 1 << "\n";
			return 0;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			swap(s[i][j], s[j][i]);
	ok = 1;
	for(int i = 0; i < n; i++)
		ok &= string::npos != s[i].find('.');
	if(ok)
	{
		for(int i = 0; i < n; i++)
			cout << s[i].find('.') + 1 << ' ' << i + 1 << "\n";
	}
	else
	{
		cout << -1 << "\n";
		return 0;
	}
    return 0;
}