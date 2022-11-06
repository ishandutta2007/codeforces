#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 1e6 + 9;
char str[MaxN + 9];
int csL[MaxN + 9];
int csR[MaxN + 9];
int dpL[MaxN + 9];
int dpR[MaxN + 9];

int f() {
	int n;
	cin >> n;

	cin >> (str + 1);

	for (int i = 1; i <= n; ++i) {
		csL[i] = csL[i - 1] + (str[i] == '(' ? 1 : -1);
		dpL[i] = min(dpL[i - 1], csL[i]);
	}

	for (int i = n; i >= 1; --i) {
		csR[i] = csR[i + 1] + (str[i] == ')' ? 1 : -1);
		dpR[i] = min(dpR[i + 1], csR[i]);
	}

	int res = 0;

	if (csL[n] == -2) {
		if(dpL[n] < -2)
			return 0;
		for (int i = 1; i <= n; ++i) {
			if (str[i] == ')')
				res++;
			if (csL[i] < 0)
				break;
		}
	} else if (csL[n] == 2) {
		if(dpR[1] < -2)
			return 0;
		for (int i = n; i >= 1; --i) {
			if (str[i] == '(')
				res++;
			if (csR[i] < 0)
				break;
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << f();
	return 0;
}