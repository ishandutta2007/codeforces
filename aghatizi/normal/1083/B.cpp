#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;

ll dist[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	string s , t;
	cin >> s >> t;

	int lcp = 0;
	while(lcp < n && s[lcp] == t[lcp])
		lcp++;

	if(lcp == n || k == 1)
		return cout << n << endl , 0;

	s = s.substr(lcp);
	t = t.substr(lcp);
	n -= lcp;

	dist[0] = 1;
	ll sum = 0;
	for(int i = 1; i <= n; i++)
	{
		dist[i] = dist[i - 1] * 2;
		dist[i] -= (s[i - 1] == 'b') + (t[i - 1] == 'a');

		if(k <= dist[i])
			return cout << sum + (1LL * k * (n - i + 1)) + lcp << endl , 0;

		sum += dist[i];
	}
	
	cout << sum + lcp << endl;
}