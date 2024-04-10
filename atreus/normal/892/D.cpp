#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

pair <int, int> p[30];

int main() {
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i].first;
		p[i].second = i;
	}
	sort (p + 1, p + n + 1);
	int k = p[1].first;
	for (int i = 1; i < n; i++)
		p[i].first = p[i + 1].first;
	p[n].first = k;
	for (int i = 1; i <= n; i++){
		int l = p[i].first;
		p[i].first = p[i].second;
		p[i].second = l;
	}
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++)
		cout << p[i].second << " ";
}