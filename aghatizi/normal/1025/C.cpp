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

	s += s;

	int n = s.size() , res = 1 , last = 1;

	for(int i = 1; i < n; i++)
	{
		if(s[i] != s[i - 1])
			last++;
		else
		{
			res = max(res , last);
			last = 1;
		}
	}

	res = max(res , last);

	cout << min(res , n / 2) << endl;
}