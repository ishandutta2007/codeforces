#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define N_ 101000
#define pii pair<int,int>
#define pil pair<int, long long>
int n, m, K, Num[N_], Ed[N_], cnt, Day[N_], Val[N_], ord[N_], Cur[N_];
vector<int>E[N_];
set<pil>Set[N_];
void DFS(int a) {
	Num[a] = ++cnt;
	ord[cnt] = a;
	for (auto &x : E[a]) {
		DFS(x);
	}
	Ed[a] = cnt;
}
int main() {
	int i;
	scanf("%d%d%d", &n, &m, &K);
	for (i = 2; i <= n; i++) {
		int a;
		scanf("%d", &a);
		E[a].push_back(i);
	}
	DFS(1);
	for (i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		Day[a] = b, Val[a] = c;
	}
	vector<pii>TP;
	for (i = 1; i <= n; i++)if (Day[i])TP.push_back({ Day[i],-Num[i] });
	sort(TP.begin(), TP.end());
	int c = 0;
	for (auto &t : TP) {
		Day[ord[-t.second]] = ++c;
	}
	for (i = n; i >= 1; i--) {
		int a = ord[i];
		if (E[a].empty()) {
			Cur[a] = a;
			if (Day[a]) {
				Set[a].insert({ Day[a], Val[a] });
			}
			continue;
		}
		int pv = -1;
		for (auto &x : E[a]) {
			if (pv == -1 || Set[Cur[pv]].size() < Set[Cur[x]].size())pv = x;
		}
		for (auto &x : E[a]) {
			if (x != pv) {
				for (auto &t : Set[Cur[x]]) {
					Set[Cur[pv]].insert(t);
				}
			}
		}
		Cur[a] = Cur[pv];
		int cur = Cur[a];
		if (Day[a]) {
			auto it = Set[cur].lower_bound({ Day[a],0ll });
			long long s = 0;
			int ck = 0;
			while (it != Set[cur].end()) {
				if (s + it->second >= Val[a]) {
					ck = 1;
					Set[cur].erase(it);
					int fi = it->first;
					long long se = s + it->second - Val[a];
					Set[cur].insert({ Day[a], Val[a] });
					if (se)Set[cur].insert({ fi,se });
					break;
				}
				else {
					s += it->second;
					auto it2 = it;
					it++;
					Set[cur].erase(it2);
				}
			}
			if (!ck) {
				Set[cur].insert({ Day[a],Val[a] });
			}
		}
	}
	long long sum = 0;
	for (auto &t : Set[Cur[1]])sum += t.second;
	printf("%lld\n", sum);
}