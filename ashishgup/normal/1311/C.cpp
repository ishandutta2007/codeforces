#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m;
char s[N];
int freq[26];
int p[N], pref[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(freq, 0, sizeof(freq));
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			pref[i] = 0;
			cin >> s[i];
			freq[s[i] - 'a']++;
		}
		pref[n + 1] = 0;
		for(int i = 1; i <= m; i++)
		{
			int x;
			cin >> x;
			pref[1]++;
			pref[x + 1]--;
		}
		for(int i = 1; i <= n; i++)
		{
			pref[i] += pref[i - 1];
			freq[s[i] - 'a'] += pref[i];
		}
		for(int i = 0; i < 26; i++)
			cout << freq[i] << " ";
		cout << endl;
	}	
	return 0;
}