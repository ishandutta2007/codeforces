#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
char p[201000];
int n;
set<int>S1, S2;
vector<vector<int> > T;
int main() {
	int i;
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		if (p[i] == '0')S1.insert(i);
		else S2.insert(i);
	}
	while (!S1.empty() || !S2.empty()) {
		vector<int>TP;
		if (!S2.empty() && S1.empty()) {
			printf("-1\n");
			return 0;
		}
		int pv = *S1.begin();
		TP.push_back(pv + 1);
		S1.erase(S1.begin());
		while (1) {
			auto p1 = S2.lower_bound(pv + 1);
			if (p1 == S2.end())break;
			auto p2 = S1.lower_bound(*p1 + 1);
			if (p2 == S1.end())break;
			TP.push_back((*p1) + 1);
			TP.push_back((*p2) + 1);
			pv = *p2;
			S1.erase(p2);
			S2.erase(p1);
		}
		T.push_back(TP);
	}
	printf("%d\n", T.size());
	for (i = 0; i < T.size(); i++) {
		printf("%d ", T[i].size());
		for (auto &t : T[i])printf("%d ", t);
		printf("\n");
	}
}