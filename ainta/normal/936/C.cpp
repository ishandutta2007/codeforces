
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
char p[2010], tp[2010];
char q[2010];

vector<int>Res;
void Rev(int L) {
	int i;
	Res.push_back(L);
	for (i = n - L; i < n; i++) {
		tp[n - 1 - i] = p[i];
	}
	for (i = 0; i < n - L; i++) {
		tp[i + L] = p[i];
	}
	for (i = 0; i < n; i++)p[i] = tp[i];
}
int C[30];
int main() {
	int i, j;
	scanf("%d", &n);
	scanf("%s", p);
	scanf("%s", q);
	for (i = 0; q[i]; i++) {
		C[p[i] - 'a']++;
		C[q[i] - 'a']--;
	}
	for (i = 0; i < 26; i++) {
		if (C[i] != 0) {
			printf("-1\n");
			return 0;
		}
	}
	for (i = 0; i < n - 1; i += 2) {
		int p1 = -1, p2 = -1;
		for (j = i; j < n; j++) {
			if (p[j] == q[i])p1 = j;
		}
		for (j = i; j < n; j++) {
			if (p[j] == q[i + 1] && j != p1)p2 = j;
		}
		int L1 = i, L2, L3 = 1, L4, L5 = 1, L6;
		if (p1 < p2) {
			L2 = p1 - i;
			L4 = p2 - p1 - 1;
			L6 = n - p2 - 1;
			Rev(L6);
			Rev(L4 + L5);
			Rev(L3);
			Rev(L1 + L2 + L4 + L5 + L6);
			Rev(L3 + L4 + L5 + L6);
			Rev(L1);
		}
		else {
			L2 = p2 - i;
			L4 = p1 - p2 - 1;
			L6 = n - p1 - 1;
			Rev(L6);
			Rev(L5);
			Rev(L3 + L4);
			Rev(L1 + L2 + L6);
			Rev(L3 + L4 + L5 + L6);
			Rev(L1);
		}
	}
	printf("%d\n", Res.size());
	for (i = 0; i < Res.size(); i++)printf("%d ", Res[i]);
}