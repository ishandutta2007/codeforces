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

	int n , m , k;
	cin >> n >> m >> k;
	k = n - k;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i + 1 < n; i++)
		a[i] = a[i + 1] - a[i] - 1;
	n--;
	sort(a , a + n);

	int res = 0;
	for(int i = 0; i < k; i++)
		res += a[i];

	cout << res + n + 1 << endl;
}