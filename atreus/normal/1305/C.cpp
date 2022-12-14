#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n > m)
		return cout << 0 << endl, 0;
	ll answer = 1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			answer = 1ll * answer * abs(a[i] - a[j]) % m;
	cout << answer << endl;
}