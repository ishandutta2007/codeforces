#include<bits/stdc++.h>

using namespace std;

const int MAX = 300005;

vector < pair <int, int> > V;
map <int, bool> M;
int n, A[MAX], i;

int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", A + i);
	int l = 1, temp = n, siz = 0;
	for (i = 1; i <= n; i++) {
		if (M.count(A[i])) {
			M.clear();
			V.push_back(make_pair(l, i));
			temp -= (i - l + 1); l = i + 1;
			++siz;
		}
		else M[A[i]] = true;
	}
	if (V.empty()) printf("-1\n");
	else if (temp) {
		printf("%d\n", siz); siz--;
		for (i = 0; i < siz; i++) printf("%d %d\n", V[i].first, V[i].second);
		printf("%d %d\n", V[siz].first, n);
	}
	else {
		printf("%d\n", siz);
		for (i = 0; i < siz; i++) printf("%d %d\n", V[i].first, V[i].second);
	}
}