#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;

int a[maxn], b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	int mx = 0;
	for (int i = 1; i <= n; i++){
		a[i] = b[i] + mx;
		mx = max(mx, a[i]);
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << '\n';
}