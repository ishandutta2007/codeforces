#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if(n > 30) return cout << m, 0;
	int a = 1;
	for(int i = 0; i < n; i++) a *= 2;
	cout << m % a;
}