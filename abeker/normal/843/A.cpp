#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N;
pii p[MAXN];
bool bio[MAXN];
vector < vector <int> > sol;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
	
	sort(p, p + N);
	
	for (int i = 0; i < N; i++) {
		if (bio[i])
			continue;
		vector <int> tmp;
		for (int x = i; !bio[x]; x = p[x].second) {
			bio[x] = true;
			tmp.push_back(x);
		}
		sol.push_back(tmp);
	}
	
	printf("%d\n", sol.size());
	for (auto it : sol) {
		printf("%d ", it.size());
		for (auto elem : it)
			printf("%d ", elem + 1);
		puts("");
	}
	
	return 0;
}