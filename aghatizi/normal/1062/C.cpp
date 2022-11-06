#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int mod = 1e9 + 7;

int t[maxn] , ps[maxn];

string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	t[0] = 1;
	for(int i = 1; i < maxn; i++)
		t[i] = 1LL * t[i - 1] * 2 % mod;

	int n , q;
	cin >> n >> q >> s;

	for(int i = 0; i < n; i++)
		ps[i + 1] = ps[i] + (s[i] == '1');

	while(q--)
	{
		int l , r;
		cin >> l >> r;
		l--;

		int T = ps[r] - ps[l];

		int res = (t[T] - 1 + mod) % mod;
		res = 1LL * res * t[r - l - T] % mod;

		cout << res << endl;
	}
}