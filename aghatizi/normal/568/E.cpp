#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int inf = 1e9 + 20;

int a[maxn] , b[maxn] , dp[maxn];

vector<int> shits[maxn];

int pos[maxn];
bool picked[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	int m;
	cin >> m;

	for(int i = 0; i < m; i++)
		cin >> b[i];

	sort(b , b + m);
	reverse(b , b + m);

	fill(dp , dp + maxn , inf);
	for(int i = 0; i < n; i++)
	{
		if(a[i] == -1)
		{
			int pt = 0;
			for(int j = 0; j < m; j++)
			{
				while(dp[pt] < b[j])
					pt++;
				while(pt > 0 && dp[pt - 1] >= b[j])
					pt--;

				dp[pt] = b[j];
			}
		}
		else
		{
			int k = lower_bound(dp , dp + maxn , a[i]) - dp;

			shits[k].pb(i);
			pos[i] = k;
			dp[k] = a[i];
		}
	}

	int k = lower_bound(dp , dp + maxn , inf) - dp - 1;

	reverse(b , b + m);

	for(int i = n - 1; i >= 0; i--)
	{
		if(a[i] == -1)
		{
			int pt = lower_bound(shits[k].begin() , shits[k].end() , i) - shits[k].begin();

			if(pt == 0 || a[shits[k][pt - 1]] >= dp[k + 1])
			{
				int x = lower_bound(b , b + m , dp[k + 1]) - b - 1;

				a[i] = dp[k] = b[x];
				picked[x] = 1;
				k--;
			}
		}
		else if(pos[i] == k)
		{
			dp[k] = a[i];
			k--;
		}

		if(k < 0)
			break;
	}

	int pt = 0;
	for(int i = 0; i < n; i++)
		if(a[i] == -1)
		{
			while(picked[pt])
				pt++;

			a[i] = b[pt];
			picked[pt] = 1;
		}

	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}