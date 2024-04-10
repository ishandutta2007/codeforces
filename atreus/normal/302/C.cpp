#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int sum = 0, a = 0, b = 1000;
	for (int i = 0; i < 2*n-1; i++){
		int x;
		cin >> x;
		sum += abs(x);
		a += (x < 0);
		b = min(b, abs(x));
	}
	if ((n & 1) or (a % 2 == 0))
		cout << sum << '\n';
	else
		cout << sum - 2 * b << endl;
}