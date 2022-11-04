#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

char ch[300010];

ll Rmin[300010];

int main() {
	/*for(int i = 0; i < (1 << 10); i++) {
		int flag = 0;
		for(int j = 0; j < 10; j++)
			for(int k = 0; j + 2 * k < 10; k++)
				if((i >> j & 1) == (i >> (j + k) & 1) && (i >> (j + k) & 1) == (i >> (j + 2 * k) & 1)) flag = 1;
		if(!flag) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");*/
	scanf("%s", ch + 1), n = strlen(ch + 1);
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		vector <int> V(0);
		int flag = 0;
		for(int j = i; j <= n; j++) {
			V.push_back(ch[j]);
			int s = (int) V.size() - 1;
			for(int k = 1; s - 2 * k >= 0; k++)
				if(V[s] == V[s - k] && V[s] == V[s - 2 * k]) {
					Rmin[i] = j;
					flag = 1;
					break;
				}
			if(flag == 1) break;
		}
		if(flag) ans += n - Rmin[i] + 1;
	}
	printf("%lld\n", ans);
	return 0;
}