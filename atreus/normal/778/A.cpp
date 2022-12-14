#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 2e5 + 5;

string t, p;
int a[maxn];

bool check (int x) {
	string k = t;
	for (int i = 0; i < x; i++)
		k[a[i]] = '!';
	int idx = 0;
	for (int i = 0; i < t.size() and idx < p.size(); i++) {
		if (k[i] == p[idx]) {
			idx ++;
		}
	}
	return (idx == p.size());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t >> p;
	for (int i = 0; i < t.size(); i++) {
		cin >> a[i];
		a[i] --;
	}
	int lo = 0, hi = t.size() + 1;
	while (hi - lo > 1) {
		int mid = (hi + lo) >> 1;
		if (check (mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << endl;
}