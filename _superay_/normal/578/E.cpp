#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, prv[N], vis[N];
char S[N];
vector<int> stkL, stkR, Ch[N], B[2][2];
int main() {
	scanf("%s", S + 1);
	n = strlen(S + 1);
	int K = 0;
	for (int i = 1; i <= n; i++) {
		if (S[i] == 'L') {
			if (stkR.size()) {
				prv[i] = stkR.back();
				stkR.pop_back();
			} else K++;
			stkL.push_back(i);
		} else {
			if (stkL.size()) {
				prv[i] = stkL.back();
				stkL.pop_back();
			} else K++;
			stkR.push_back(i);
		}
	}
	printf("%d\n", K - 1);
	int cnt = 0;
	for (int i = n; i; i--) if (!vis[i]) {
		++cnt;
		int j = i;
		while (j) {
			vis[j] = 1;
			Ch[cnt].push_back(j);
			j = prv[j];
		}
		reverse(Ch[cnt].begin(), Ch[cnt].end());
		int x = (S[Ch[cnt][0]] == 'R');
		int y = (S[Ch[cnt].back()] == 'R');
		B[x][y].push_back(cnt);
	}
	vector<int> ans, B2, B01, B10, BB;
	if (B[0][0].size() || B[1][1].size()) {
		if (B[0][0].size() < B[1][1].size()) B[0][0].swap(B[1][1]);
		if (B[0][0].size() > B[1][1].size()) {
			B2 = Ch[B[0][0][0]];
			for (int i = 0; i < (int)B[1][1].size(); i++) {
				B2.insert(B2.end(), Ch[B[1][1][i]].begin(), Ch[B[1][1][i]].end());
				B2.insert(B2.end(), Ch[B[0][0][i + 1]].begin(), Ch[B[0][0][i + 1]].end());
			}
		} else {
			for (int i = 0; i < (int)B[1][1].size(); i++) {
				B2.insert(B2.end(), Ch[B[0][0][i]].begin(), Ch[B[0][0][i]].end());
				B2.insert(B2.end(), Ch[B[1][1][i]].begin(), Ch[B[1][1][i]].end());
			}
			Ch[++cnt] = B2;
			B[0][1].push_back(cnt);
			B2.clear();
		}
	}
	for (int i = 0; i < (int)B[0][1].size(); i++) {
		B01.insert(B01.end(), Ch[B[0][1][i]].begin(), Ch[B[0][1][i]].end());
	}
	for (int i = 0; i < (int)B[1][0].size(); i++) {
		B10.insert(B10.end(), Ch[B[1][0][i]].begin(), Ch[B[1][0][i]].end());
	}
	if (B01.size() && B10.size()) {
		if (B01.back() < B10.back()) B01.swap(B10);
		B10.push_back(B01.back());
		B01.pop_back();
		BB = B01;
		BB.insert(BB.end(), B10.begin(), B10.end());
	} else if (B01.size()) BB = B01;
	else BB = B10;
	if (B2.size() && BB.size()) {
		if (S[BB.back()] == S[B2[0]]) BB.swap(B2);
		ans = BB;
		ans.insert(ans.end(), B2.begin(), B2.end());
	} else if (B2.size()) ans = B2;
	else ans = BB;
	assert((int)ans.size() == n);
	for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i == n - 1]);
	return 0;
}