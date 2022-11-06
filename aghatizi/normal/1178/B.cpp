#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

int cntl[maxn] , cntr[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int n = s.size();
	for(int i = 1; i < n; i++)
		cntl[i] = cntl[i - 1] + (s[i - 1] == s[i] && s[i] == 'v');
	for(int i = n - 2; i >= 0; i--)
		cntr[i] = cntr[i + 1] + (s[i + 1] == s[i] && s[i] == 'v');

	ll res = 0;
	for(int i = 0; i < n; i++)
		if(s[i] == 'o')
			res += 1LL * cntl[i] * cntr[i];

	cout << res << endl;
}