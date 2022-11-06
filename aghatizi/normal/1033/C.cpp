#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

bool dp[maxn];

int p[maxn] , a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> p[i] , a[p[i]] = i; 

	for(int i = n; i >= 1; i--)
		for(int j = i; j <= n; j += i)
		{
			if(1 <= a[i] - j && a[i] - j <= n && p[a[i] - j] > i)
				dp[i] |= !dp[p[a[i] - j]];

			if(1 <= a[i] + j && a[i] + j <= n && p[a[i] + j] > i)
				dp[i] |= !dp[p[a[i] + j]];
		}

	for(int i = 1; i <= n; i++)
		cout << (char)('A' + (!dp[p[i]]));
	cout << endl;
}