#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

int x[maxn] , y[maxn] , tmp[maxn];

ll res[maxn] , ans[maxn];

bool cmp(int a , int b)
{
	return x[a] - y[a] < x[b] - y[b];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// min(x[i] + y[j] , x[j] + y[i])
	// x[i] - y[i] <= x[j] - y[j]

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i] , tmp[i] = i;

	sort(tmp , tmp + n , cmp);

	ll sum = 0;
	for(int i = n - 1; i >= 0; i--)
		res[i] = sum , sum += y[tmp[i]];

	sum = 0;
	for(int i = 0; i < n; i++)
		res[i] += sum , sum += x[tmp[i]];

	for(int i = 0; i < n; i++)
	{
		int ind = tmp[i];
		res[i] += 1LL * y[ind] * i + 1LL * x[ind] * (n - i - 1);

		ans[ind] = res[i];
	}

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		int k = min(x[a] + y[b] , x[b] + y[a]);

		ans[a] -= k;
		ans[b] -= k;
	}

	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
}