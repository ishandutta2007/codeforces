#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int p[maxn], q[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n % 2 == 0)
		return cout << -1 << endl, 0;
	for (int i = 0; i < n; i++)
		cout << (p[i] = i) << " ";
	cout << endl;
	cout << (q[0] = n-1) << " ";
	for (int i = 0; i < n-1; i++)
		cout << (q[i+1] = i) << " ";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << (p[i] + q[i]) % n << " ";
	cout << endl;
}