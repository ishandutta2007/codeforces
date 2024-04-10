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

	string s;
	cin >> s;

	for(int _ = 0; _ < 5; _++)
	{
		string t;
		cin >> t;

		if(t[0] == s[0] || t[1] == s[1])
			return cout << "YES" << endl , 0;
	}

	cout << "NO" << endl;
}