/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
int a[maxn], b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	if (a[1] != b[1] or a[n] != b[n])
		return cout << "No" << endl, 0;
	for (int i = 1; i < n; i++)
		a[i] = a[i + 1] - a[i];
	for (int i = 1; i < n; i++)
		b[i] = b[i + 1] - b[i];
	sort(a + 1, a + n);
	sort(b + 1, b + n);
	for (int i = 1; i < n; i++)
		if (a[i] != b[i])
			return cout << "No" << endl, 0;
	cout << "Yes" << endl;
}