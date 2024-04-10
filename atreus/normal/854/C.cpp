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
long long c[maxn], tim[maxn];

int main() {
    ios_base::sync_with_stdio(false);
	long long ans = 0, n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		if (i <= k)
			qu.push(make_pair(c[i], i));
	}
	for (int i = k + 1; i <= n + k; i++){
		if (i <= n)
			qu.push(make_pair(c[i], i));
		tim[qu.top().second] = i;
		ans += (i - qu.top().second) * qu.top().first;
		qu.pop();
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		cout << tim[i] << " ";
}