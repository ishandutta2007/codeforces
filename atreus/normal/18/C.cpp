#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int maxn = 3e5 + 500;
priority_queue <pair <long long, long long> > qu;
long long a[maxn], tim[maxn];

int main() {
    ios_base::sync_with_stdio(false);
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	if (n == 1)
		return cout << 0, 0;
	double miangin = 1.0 * sum / 2;
	int k = a[0], cnt = 0;
	if (k == miangin)
		cnt ++;
	for (int i = 1; i < n - 1; i++){
		k += a[i];
		if (k == miangin)
			cnt ++;
	}
	cout << cnt << endl;
}