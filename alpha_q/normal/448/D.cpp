#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e15;

long long n, m, k;

bool Check (long long x) {
	long long count = 0;
	for (int i = 1; i <= n; i++) count += min(m, (x - 1)/i);
	return count < k; 
}

long long Search (long long l, long long r) {
	if (l == r) return l;
	long long mid = (l + r) >> 1;
	if (Check(mid)) return Search(mid + 1, r);
	return Search(l, mid);
}

int main() {	
	//freopen("input.txt", "r", stdin);

	cin >> n >> m >> k;
	cout << Search(1, INF) - 1 << endl;
    return 0;
}