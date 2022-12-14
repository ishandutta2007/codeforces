#include <iostream>
#include <algorithm>

using namespace std;


const int maxn = 1e5 + 100;

long long w[maxn];
int a[maxn];
int b[maxn];
bool mark[maxn];

long long f(int r) { // l <= r,  javabe masale ro vase 0, 1, ta b[r] return konim!
	if (mark[r] == true) {
		return w[r];
	}
	if (1 > r)
		return 0;
	if (1 == r) {
		return r * b[r];
	}
	w[r] = max(f(r - 2) + 1ll * r * b[r], f(r - 1));
	mark[r] = true;
	return w[r];
}

int main() {
    int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
        b[a[i]]++;
	}
	cout << f(maxn - 1) << endl;
}