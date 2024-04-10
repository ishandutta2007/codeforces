#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

pii get(int x, int y) {
	bool a[10] = {0}, b[10] = {0};
	int bulls = 0;
	for (int i = 0; i < 4; i++) {
		if (x % 10 == y % 10)
			bulls++;
		a[x % 10] = true;
		b[y % 10] = true;
		x /= 10;
		y /= 10;
	}
	int cows = 0;
	for (int i = 0; i < 10; i++)
		if (a[i] && b[i])
			cows++;
	cows -= bulls;
	return {bulls, cows};
}

int main() {
	vector <int> curr;
	for (int i = 0; i < 10000; i++) {
		bool bio[10] = {0};
		int x = i;
		bool ok = true;
		for (int j = 0; j < 4; j++) {
			ok &= !bio[x % 10];
			bio[x % 10] = true;
			x /= 10;
		}
		if (ok)
			curr.push_back(i);
	}
	
	while (1) {
		int mini = 10000, best = -1;
		for (int i = 0; i < 5000; i++) {
			int cnt[5][5] = {0};
			int mx = 0;
			int r = rand() % 10000;
			for (int it : curr) {
				pii tmp = get(it, r);
				mx = max(mx, ++cnt[tmp.first][tmp.second]);
			}
			if (mx < mini) {
				mini = mx;
				best = r;
			}
		}
		if (curr.size() == 1)
			best = curr[0];
		printf("%04d\n", best);
		fflush(stdout);
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == 4 && b == 0) 
			return 0;
		vector <int> nxt;
		for (int it : curr)
			if (get(it, best) == pii(a, b))
				nxt.push_back(it);
		curr = nxt;
	}
	
	return 0;
}