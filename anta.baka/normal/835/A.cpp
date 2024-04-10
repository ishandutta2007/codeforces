#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int a = 2 * t1 + s * v1;
	int b = 2 * t2 + s * v2;
	cout << (a == b ? "Friendship" : a < b ? "First" : "Second");
}