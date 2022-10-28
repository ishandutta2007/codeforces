#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
string s;

int32_t main()
{
	IOS;
	cin >> s;
	n = s.size();
	int cnt = 0;
	for(int i = 0, j = n - 1; i < j; i++, j--)
		cnt += (s[i] != s[j]);
	if(n % 2 && cnt <= 1)
		cout << "YES" << endl;
	else if(n % 2 == 0 && cnt == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}