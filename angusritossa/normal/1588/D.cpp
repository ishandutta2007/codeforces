#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int n;
int occ[150][10][2];
int getOcc(int ch, int word, int pos) {
	if (occ[ch][word][0] > pos) return 0;
	if (occ[ch][word][1] > pos) return 1;
	return -1;
}
int done[1024][150], upto;
int memo[1024][150];
vector<int> chars;
int dp(int b, int c) {
	if (done[b][c] == upto) return memo[b][c];
	done[b][c] = upto;
	//D("dp %d %d\n", b, c);
	int ans = 1;
	for (int d : chars) {
		int newb = 0;
		for (int i = 0; i < n; i++) {
			int o = getOcc(d, i, occ[c][i][!!(b & (1 << i))]);
			if (o == -1) {
				newb = -1;
				break;
			}
			if (o) newb |= (1 << i);
		}
		if (newb != -1) {
			ans = max(ans, 1+dp(newb, d));
		}	
	}
	return memo[b][c] = ans;
}
vector<char> ansStr;
void findAns(int b, int c) {
	if (c) {
		ansStr.push_back(c);
	}
	for (int d : chars) {
		int newb = 0;
		for (int i = 0; i < n; i++) {
			int o = getOcc(d, i, occ[c][i][!!(b & (1 << i))]);
			if (o == -1) {
				newb = -1;
				break;
			}
			if (o) newb |= (1 << i);
		}
		if (newb != -1) {
			if (1+dp(newb, d) == memo[b][c]) {
				findAns(newb, d);
				return;
			}
		}	
	}
}
char inp[200];
int main() {
	int t;
	for (int c = 'A'; c <= 'Z'; c++) chars.push_back(c);
	for (int c = 'a'; c <= 'z'; c++) chars.push_back(c);
	scanf("%d", &t);
	for (int _ = 0; _ < t; _++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int c : chars) {
				occ[c][i][0] = occ[c][i][1] = -1;
			}
			scanf(" %s", inp);
			int len = strlen(inp);
			for (int j = 0; j < len; j++) {
				if (occ[inp[j]][i][0] == -1) {
					occ[inp[j]][i][0] = j;
				} else {
					occ[inp[j]][i][1] = j;
				}
			}
			occ[0][i][0] = -1;
		}
		// run the dp
		upto++;
		int ans = dp(0, 0)-1;
		printf("%d\n", ans);
		ansStr.clear();
		findAns(0, 0);
		for (auto c : ansStr) printf("%c", c);
		printf("\n");
	}
}