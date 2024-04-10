#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		bool flag = 0;
		for (int i = 31; i >= 0; i--) {
			int cnt = 0;
			for (int j = 1; j <= n; j++)
				if (a[j] & (1 << i)) ++cnt;
			if ((cnt & 3) == 1) flag = 1, puts("WIN");
			else if ((cnt & 3) == 3) flag = 1, puts((n&1)?"LOSE":"WIN");
			if (flag) break;
		}
		if (!flag) puts("DRAW");
	}
}