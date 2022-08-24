#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[101000];
int S[101000], C[1010000], T[1010000];
bool OK(int b, int e) {
	int i;
	for (i = b + 1; i <= e; i++) {
		if (w[i] > 0) {
			C[w[i]]++;
			T[w[i]]++;
		}
		else {
			C[-w[i]]--;
			if (C[-w[i]] < 0)return false;
			T[-w[i]]++;
		}
	}
	for (i = b + 1; i <= e; i++) {
		int a = abs(w[i]);
		if (C[a])return false;
		if (T[a] > 2)return false;
		T[a] = 0;
	}
	return true;
}
int main() {
	int i;
	scanf("%d", &n);
	vector<int>V;
	V.push_back(0);
	for (i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		w[i] = a;
		S[i] = S[i - 1];
		if (a > 0) {
			S[i]++;
		}
		else {
			S[i]--;
		}
		if (!S[i])V.push_back(i);
	}
	if (V.back() != n) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i < V.size(); i++) {
		if (!OK(V[i - 1], V[i])) {
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", V.size()-1);
	for (int i = 1; i < V.size(); i++)printf("%d ", V[i] - V[i - 1]);
}