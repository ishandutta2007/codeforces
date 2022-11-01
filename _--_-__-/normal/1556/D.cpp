#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, k, a[10005];
int fsum(int x, int y)
{
	x ++; y ++;
	int u, v;
	cout << "or " << x << ' ' << y << endl;
	cin >> u;
	cout << "and " << x << ' ' << y << endl;
	cin >> v;
	return u + v;
}

int main()
{
	cin >> n >> k; k --;
	int s01 = fsum(0, 1), s12 = fsum(1, 2), s20 = fsum(2, 0);
	LL ts = (LL)s01 + s12 + s20; ts /= 2;
	a[0] = ts - s12; a[1] = ts - s20; a[2] = ts - s01;
	for(int i = 3; i < n; i ++) a[i] = fsum(0, i) - a[0];
	sort(a, a + n);
	cout << "finish " << a[k] << endl;
	return 0;
}