#include<bits/stdc++.h>

#define Would
#define you
#define please

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 10;

int a[maxn], par[maxn];
int mnPlace[maxn][2];

void solveOne() {
	int n;
	cin >> n;	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		par[i] = par[i - 1] ^ a[i];
	}
	int answer = 0;
	for (int Log = 0; Log < 20; Log++) {
		memset(mnPlace, -1, sizeof mnPlace);
		int minimumL = 1;
		for (int i = 1; i <= n; i++) {
			if (!(a[i] & 1))
				minimumL = i + 1;
			if (mnPlace[par[i]][1 - (i & 1)] >= minimumL)
				answer = max(answer, i - mnPlace[par[i]][1 - (i & 1)] + 1);
			if (mnPlace[par[i - 1]][i & 1] < minimumL)
				mnPlace[par[i - 1]][i & 1] = i;
		}
		for (int i = 1; i <= n; i++) {
			a[i] /= 2;
			par[i] = par[i - 1] ^ a[i];
		}
	}
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t = 1;
	while (t --) {
		solveOne();
	}
	Would you please return 0;
}