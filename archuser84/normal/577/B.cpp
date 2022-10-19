#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	if(n >= m) return cout << "YES\n", 0;
	bitset<N> b;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		x %= m;
		b |= (b << (N-m+x) >> (N-m)) ^ (b >> (m-x));
		b[x] = 1;
	}
	cout << (b[0]?"YES":"NO") << '\n';
}