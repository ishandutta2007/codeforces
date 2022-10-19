#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int N;
vector <int> ch[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		int x;
		scanf("%d", &x);
		ch[x].push_back(i);
	}
	
	bool ok = true;
	for (int i = 1; i <= N; i++)
		if (!ch[i].empty()) {
			int cnt = 0;
			for (auto it : ch[i])
				cnt += ch[it].empty();
			ok &= cnt >= 3;
		}
	
	puts(ok ? "Yes" : "No");
	
	return 0;
}