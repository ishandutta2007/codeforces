#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
const int max_n = 200005;
int n, k;
int a[max_n];
int x;
vector<pair<int, int>> v;
int main()
{
	cin >> n >> k;
	assert(k <= n);
	for (int i = 0; i < n; i++) {
		cin >> x; a[x]++;
	}
    for (int i = 1; i < max_n;i++)
        for (int j = 1; j <= a[i]; j++)
			v.push_back({a[i] / j, i});
	assert(v.size() == n);
	assert(k <= n);
	sort(v.begin(), v.end());
	assert(k <= n);
	assert(v.size() >= k);
	for (int i = int(v.size()) - 1; i >= int(v.size()) - k; i--) 
		cout << v[i].second << ' ';
}