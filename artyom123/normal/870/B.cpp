#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> a;
	multiset <int> b;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		a.push_back(m);
		b.insert(m);
}
	if (k == 1) {
		cout << *b.begin();
		return 0;
	} if (k >= 3) {
		cout << *b.rbegin();
		return 0;
	}
	else {
		vector <int> part1;
		vector <int> part2 = a;
		part2.erase(part2.begin());
		part1.push_back(a[0]);
		multiset <int> set1;
		multiset <int> set2 = b;
		set2.erase(set2.find(a[0]));
		set1.insert(a[0]);
		int max1 = max(*set1.begin(), *set2.begin());
		for (int i = 1; i < n - 1; i++) {
			set2.erase(set2.find(a[i]));
			set1.insert(a[i]);
			if (max1 < max(*set1.begin(), *set2.begin())) {
				max1 = max(*set1.begin(), *set2.begin());
			}
		} cout << max1;
	}
	return 0;

}