#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	int res = 0;
	for(int i = 0; i < n; i++)
	{
		int j = i;
		while(j + 1 < n && a[j] != a[j + 1])
			j++;

		res = max(res , j - i + 1);
		i = j;
	}

	cout << res << endl;
}