#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int>> getFact(int x) {
	vector<pair<int, int>> v;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			v.emplace_back(i, 1);
			for (x /= i; x % i == 0; x /= i)
				v.back().second++;
		}
	if (x != 1)
		v.emplace_back(x, 1);

	return v;
}

const int MaxV = 7000;
const int MaxN = (int) 1e5;

bitset<MaxV + 1> singletons[MaxV + 1];
bitset<MaxV + 1> qMask[MaxV + 1];
bitset<MaxV + 1> sets[MaxN + 1];

void pre() {
	for (int i = 0; i <= MaxV; ++i)
		for (int j = 1; j <= MaxV; ++j)
			singletons[i][j] = i % j == 0;

	vector<int> v;
	for (int i = 1; i <= MaxV; ++i) {
		auto fact = getFact(i);
		if (all_of(fact.begin(), fact.end(), [](const pair<int, int> &p) {
			return p.second == 1;
		}))
			v.push_back(i);
	}

	for (int i = 1; i <= MaxV; ++i) {
		for (const int &x : v) {
			if (x * i > MaxV)
				break;
			qMask[i][x * i] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	pre();

	int N, Q;
	cin >> N >> Q;

	while (Q--) {
		int type;
		cin >> type;
		switch (type) {
		case 1: {
			int x, v;
			cin >> x >> v;
			sets[x] = singletons[v];
			break;
		}
		case 2: {
			int x, y, z;
			cin >> x >> y >> z;
			sets[x] = sets[y] ^ sets[z];
			break;
		}
		case 3: {
			int x, y, z;
			cin >> x >> y >> z;
			sets[x] = sets[y] & sets[z];
			break;
		}
		case 4: {
			int x, v;
			cin >> x >> v;
			bitset<MaxV + 1> b = sets[x] & qMask[v];
			cout << (b.count() & 1);
			break;
		}
		default:
			assert(false);
		}
	}

	return 0;
}