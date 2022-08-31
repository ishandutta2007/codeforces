#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
int n, K;
char p[2010];
vector<pii>Res;
void Make1(int a, char ch) {
	if (p[a] == ch)return;
	int i;
	for (i = a; i < n; i++) {
		if (p[i] == ch) {
			Res.push_back({ a + 1,i + 1 });
			reverse(p + a, p + i + 1);
			return;
		}
	}
}
void Solve() {
	int i;
	Res.clear();
	scanf("%d%d", &n, &K);
	scanf("%s", p);
	for (i = 0; i < (K - 1) * 2; i++) {
		if (i % 2 == 0)Make1(i,'(');
		else Make1(i,')');
	}
	int pv = (K - 1) * 2;
	for (i = pv; i < (pv + n) / 2; i++) {
		Make1(i,'(');
	}
	for (i = (pv + n) / 2; i < n; i++) {
		Make1(i,')');
	}
	printf("%d\n", Res.size());
	for (auto &t : Res)printf("%d %d\n", t.first, t.second);
	//printf("%s\n", p);
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}