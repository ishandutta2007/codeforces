/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
int a[maxn], b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if (1ll * k * (k - 1) < n)
		return cout << "NO" << endl, 0;
	int tmp = 1;
	for (int i = 1; tmp <= n and i <= k; i++){
		for (int j = i + 1; tmp <= n and j <= k; j++){
			a[tmp + 0] = i;
			a[tmp + 1] = j;
			
			b[tmp + 0] = j;
			b[tmp + 1] = i;

			tmp += 2;
		}
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " " << b[i] << '\n';
}