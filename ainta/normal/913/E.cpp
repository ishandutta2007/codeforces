#include<cstdio>
#include<algorithm>
#include<queue>
#include<string>
#define pii pair<int,int>
using namespace std;
int D[256][3], Path[256][4][4], vis[256][4];
string S[256][3];
priority_queue<pii>PQ;
int xx = 15, yy = 3 * 16 + 3, zz = 64 + 16 + 4 + 1;
void Ins(int a, int pv, string P) {
	int d = P.size();
	if (D[a][pv] < d || (D[a][pv]==d && S[a][pv] < P))return;
	D[a][pv] = d;
	S[a][pv] = P;
	PQ.push({ -d,a * 3 + pv });
}
int main() {
	int i, j;
	for (i = 0; i < 256; i++)for (j = 0; j < 3; j++)D[i][j] = 1e9;
	Ins(xx, 0, "x");
	Ins(yy, 0, "y");
	Ins(zz, 0, "z");
	while (!PQ.empty()) {
		pii tp = PQ.top();
		PQ.pop();
		int a = tp.second / 3, pv = tp.second % 3;
		if (vis[a][pv])continue;
		vis[a][pv] = 1;
		int d = -tp.first;
		string str = S[a][pv];
		if (pv == 0) {
			Ins(255 - a, 0, "!" + str);
		}
		for (i = 0; i < 256; i++) {
			for (j = 0; j < 2; j++) {
				if (vis[i][j]) {
					if (pv == 0 && j <= 1) Ins(a & i, 1, S[i][j] + "&" + str);
					if (j == 0 && pv <= 1) Ins(a & i, 1, str + "&" + S[i][j]);
					if (pv <= 1 && j <= 2) Ins(a | i, 2, S[i][j] + "|" + str);
					if (pv <= 2 && j <= 1) Ins(a | i, 2, str + "|" + S[i][j]);
				}
			}
		}
		Ins(a, 0, "(" + str + ")");
	}
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		char p[10];
		scanf("%s", p);
		int s = 0;
		for (i = 0; i < 8; i++)s += (p[i] - '0') << (7-i);
		int dd = min(min(D[s][0], D[s][1]), D[s][2]);
		string res="";
		for (i = 0; i < 3; i++) {
			if (D[s][i] == dd && (res == "" || res > S[s][i]))res = S[s][i];
		}
		printf("%s\n", res.c_str());
	}
}