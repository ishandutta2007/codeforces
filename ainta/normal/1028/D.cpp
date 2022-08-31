#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
map<int, int>Map;
set<int>Set1, Set2, Set;
int TH, res = 1, Mod = 1000000007;
char p[15];
int main() {
	int n, i, a;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", p);
		scanf("%d", &a);
		if (p[1] == 'D') {
			int bb = Set1.empty() ? -1e9 : *Set1.rbegin();
			int ee = Set2.empty() ? 1e9 : *Set2.begin();
			if (bb<a && a<ee) {
				Set.insert(a);
			}
			else {
				if (a < bb) {
					Set1.insert(a);
				}
				else Set2.insert(a);
			}
			continue;
		}
		if (Set.find(a)!=Set.end()) {
			res = res * 2 % Mod;
			Set.erase(a);
			for (auto &x : Set) {
				if (x < a)Set1.insert(x);
				else Set2.insert(x);
			}
			Set.clear();
		}
		else if (Set1.find(a) != Set1.end()) {
			auto it = Set1.end();
			it--;
			if (*it != a) {
				puts("0");
				return 0;
			}
			Set1.erase(it);
			for (auto &x : Set)Set2.insert(x);
			Set.clear();
		}
		else if (Set2.find(a) != Set2.end()) {
			auto it = Set2.begin();

			if (*it != a) {
				puts("0");
				return 0;
			}
			Set2.erase(it);
			for (auto &x : Set)Set1.insert(x);
			Set.clear();
		}
		else {
			puts("0");
			return 0;
		}
	}
	if (!Set.empty()) {
		int t = Set.size();
		t++;
		res = 1ll*res*t% Mod;
	}
	printf("%d\n", res);
}