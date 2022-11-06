#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , s;
	cin >> n >> s;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	sort(a , a + n);

	int k = lower_bound(a , a + n , s) - a;

	ll res = 0;
	for(int i = n / 2; i < k; i++)
		res += s - a[i];

	for(int i = k; i <= n / 2; i++)
		res += a[i] - s;

	cout << res << endl;




}