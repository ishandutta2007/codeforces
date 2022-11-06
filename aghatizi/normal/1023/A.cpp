#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	string s , t;
	cin >> s >> t;

	int pos = -1;
	for(int i = 0; i < n; i++)
		if(s[i] == '*')
			pos = i;

	if(pos == -1)
	{
		if(s == t)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}

	if(n > m + 1)
		return cout << "NO" << endl , 0;

	if(n == m + 1)
	{
		s.erase(pos , 1);

		if(s != t)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

		return 0;
	}

	string tmp = s.substr(0 , pos);
	tmp += t.substr(pos , m - n + 1);
	tmp += s.substr(pos + 1);

	if(tmp != t)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

}