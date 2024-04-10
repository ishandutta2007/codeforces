#include <bits/stdc++.h> 

using namespace std;

const int N = 2e5 + 10;

int n;
char s[N];
bitset <6> mark;
map <char, int> to;
int op[7];

int main (int argc, char const *argv[]) {
	to['L'] = 1, to['R'] = 2;
	to['U'] = 3, to['D'] = 4;
	op[1] = 2, op[2] = 1, op[3] = 4, op[4] = 3;
	scanf("%d %s", &n, s + 1);
	int tot = 1;
	for (int i = 1; i <= n; ++i) {
		int now = to[s[i]];
		if (mark[op[now]]) {
			++tot;
			mark.reset();
		}
		mark[now] = 1;
	}
	printf("%d\n", tot);
	return 0;
}