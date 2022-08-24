#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
set<int>Set;
char p[1010000];
int n, Q[5010000], head, tail, D[1010000], R;
void Put(int a, int c) {
	if (D[a])return;
	D[a] = c;
	Q[++tail] = a;
}
int main() {
	scanf("%s", p + 1);
	int i, cc = 1;
	for (i = 1; p[i]; i++) {
		Set.insert(i);
		if (i != 1 && p[i] != p[i - 1]) {
			Put(i, 1);
			Put(i - 1, 1);
		}
	}
	n = i - 1;
	while (head < tail) {
		cc++;
		int hh = head, tt = tail;
		for (i = hh; i <= tt; i++) {
			Set.erase(Q[i]);
		}
		head = tt;
		for (i = hh; i <= tt; i++) {
			auto it = Set.lower_bound(Q[i]);
			if (it != Set.begin() && it != Set.end()) {
				auto it2 = it;
				it2--;
				if (p[*it2] != p[*it]) {
					Put(*it, cc);
					Put(*it2, cc);
				}
			}
		}
	}
	printf("%d\n", cc-1);
}