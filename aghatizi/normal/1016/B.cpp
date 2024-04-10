#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int sum[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , q;
	cin >> n >> m >> q;

	string s , t;
	cin >> s >> t;

	for(int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + (i + m <= n && s.substr(i , m) == t);

	while(q--)
	{
		int l , r;
		cin >> l >> r;
		r -= m;
		l--;

		if(r < l)
			cout << 0 << endl;
		else
			cout << sum[r + 1] - sum[l] << endl;
	}

}