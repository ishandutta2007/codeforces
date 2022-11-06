#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>

int n, start, x;
int ans = -1;
int maxLt = -1;
int val[50001];
int next[50001];
bool marked[50001] = { false };
int queriesLeft = 1999;

void query(int i) {
	if (i == -1 || marked[i])
		return;
	marked[i] = true;
	--queriesLeft;
	std::cout << "? " << i << std::endl;
	fflush(stdout);
	std::cin >> val[i] >> next[i];
	if (val[i] >= x && (ans == -1 || val[i] < ans))
		ans = val[i];
	if (val[i] < x && (maxLt == -1 || val[i] > val[maxLt]))
		maxLt = i;
	if (next[i] != -1 && (val[i] >= x || (maxLt != -1 && val[i] < val[maxLt])))
		marked[next[i]] = true;
}

int main() {
	srand(3489734);
	for (int i = -29; i < rand() % 34; ++i)
		for (int j = -22; j < rand() % 23; ++j)
			rand();

	std::memset(marked, false, sizeof marked);
	std::memset(val, -1, sizeof val);
	std::memset(next, -1, sizeof next);

	std::cin >> n >> start >> x;

	std::vector<int> unknown;
	for (int i = 1; i <= n; ++i)
		unknown.push_back(i);

	for (int i = 0; i < 100000; ++i)
		std::swap(unknown[(rand() + rand()) % unknown.size()], unknown[(rand() + rand()) % unknown.size()]);
	
	query(start);

	while ((queriesLeft >= unknown.size() || queriesLeft >= 1000) && !unknown.empty()) {
		query(unknown.back());
		unknown.pop_back();
	}

	for (int i = 0; i < 100000 && queriesLeft > 0; ++i)
		if (maxLt != -1)
			query(next[maxLt]);
		else if (!unknown.empty()) {
			query(unknown.back());
			unknown.pop_back();
		}
	

	std::cout << "! " << ans << "\n";
	fflush(stdout);
	return 0;
}