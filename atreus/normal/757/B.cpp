#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[x] ++;
	}
	n = 100000;
	for (int i = 1; i <= n; i++)
		for (int j = i + i; j <= n; j += i)
			a[i] += a[j];
	cout << max(1, *max_element(a + 2, a + n + 1)) << '\n';
}