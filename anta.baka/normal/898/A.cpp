#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a = n;
	while(a % 10) a++;
	int b = n;
	while(b % 10) b--;
	if(a - n < n - b) cout << a;
	else cout << b;
}