#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
int n, chk[101000][4], par[101000], Col[101000], Z[101000], pp[101000][2], DEBUG = 0;

int DCol[101000];
char p[101000];
vector<int>Res[4];
vector<pii>T;
void init() {
	T.clear();
}
void Add(int a, int b) {
	if (a > n || b > n || a < 1 || b < 1)return;
	T.push_back({ a,b });
}
void Query() {
	if (T.empty())return;
	if (!DEBUG) {
		printf("Q %d ", T.size());
		for (auto &t : T) {
			printf("%d %d ", t.first, t.second);
		}
		puts("");
		fflush(stdout);
		scanf("%s", p);
	}
	if (DEBUG) {
		int i;
		for (i = 0; i < T.size(); i++) {
			if (DCol[T[i].first] == DCol[T[i].second])p[i] = '1';
			else p[i] = '0';
		}
	}
}
void Solve() {
	int i, j;
	scanf("%d", &n);
	if (DEBUG) {
		for (i = 1; i <= n; i++) {
			DCol[i] = rand() % 3 + 1;
		}
	}
	for (i = 1; i <= n; i++) {
		par[i] = 0;
		Col[i] = 0;
		Z[i] = 0;
	}
	for (i = 1; i <= n; i++)for (j = 1; j <= 3; j++)chk[i][j] = 0;
	{
		init();
		for (i = 1; i <= n; i += 2) {
			Add(i, i + 1);
		}
		Query();
		for (i = 0; i < T.size(); i++) {
			chk[T[i].second][T[i].second - T[i].first] = p[i] - '0';
		}
	}
	{
		init();
		for (i = 2; i <= n; i += 2) {
			Add(i, i + 1);
		}
		Query();
		for (i = 0; i < T.size(); i++) {
			chk[T[i].second][T[i].second - T[i].first] = p[i] - '0';
		}
	}

	{
		init();
		for (i = 1; i <= n; i += 4) {
			Add(i, i + 2);
			Add(i+1, i + 3);
		}
		Query();
		for (i = 0; i < T.size(); i++) {
			chk[T[i].second][T[i].second - T[i].first] = p[i] - '0';
		}
	}
	{
		init();
		for (i = 3; i <= n; i += 4) {
			Add(i, i + 2);
			Add(i + 1, i + 3);
		}
		Query();
		for (i = 0; i < T.size(); i++) {
			chk[T[i].second][T[i].second - T[i].first] = p[i] - '0';
		}
	}
	int uu = 0;
	vector<int>VV;
	for (i = 1; i <= n; i++) {
		if (!chk[i - 1][1])uu = i - 1;
		if (chk[i][1])par[i] = i - 1;
		else if (chk[i][2])par[i] = i - 2;
		else if (i>=3 && !chk[i][1] && !chk[i - 1][1] && !chk[i][2]) {
			par[i] = -1;
			pp[i][0] = i - 1;
			pp[i][1] = i - 2;
		}
		if (i == 1) {
			Col[i] = 1;
			continue;
		}
		if (par[i]) continue;
		if (uu == 1) {
			Col[i] = 2;
			continue;
		}
		Z[i] = uu-1;
		VV.push_back(i);
	}
	init();
	for (i = 0; i < VV.size(); i += 2) {
		Add(Z[VV[i]], VV[i]);
	}
	Query();

	for (i = 0; i < T.size(); i++) {
		int x = T[i].second, pa = T[i].first;
		if (p[i] == '1')par[x] = pa;
		else {
			par[x] = -1;
			pp[x][0] = pa;
			pp[x][1] = x - 1;
		}
	}

	init();
	for (i = 1; i < VV.size(); i += 2) {
		Add(Z[VV[i]], VV[i]);
	}
	Query();
	for (i = 0; i < T.size(); i++) {
		int x = T[i].second, pa = T[i].first;
		if (p[i] == '1')par[x] = pa;
		else {
			par[x] = -1;
			pp[x][0] = pa;
			pp[x][1] = x - 1;
		}
	}
	Res[1].clear();
	Res[2].clear();
	Res[3].clear();
	for (i = 1; i <= n; i++) {
		if (Col[i])continue;
		if (par[i] != -1) {
			Col[i] = Col[par[i]];
		}
		else {
			Col[i] = 6 - Col[pp[i][0]] - Col[pp[i][1]];
		}
	}
	for (i = 1; i <= n; i++) {

		Res[Col[i]].push_back(i);
	}
	if (!DEBUG) {
		printf("A %d %d %d\n", Res[1].size(), Res[2].size(), Res[3].size());
		for (i = 1; i <= 3; i++) {
			for (auto &x : Res[i])printf("%d ", x);
			puts("");
		}
		fflush(stdout);
	}
	else {
		for (i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if ((Col[i] == Col[j]) != (DCol[i] == DCol[j])) {
					puts("Wrong");
				}
			}
		}
	}
}
int main() {
	srand(1879);
	int TC, i, j;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}