#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N;
int num[MAXN];
char a[MAXN], b[MAXN];
int occ[4];
ll cnt[4][4];

int main() {
	scanf("%d%s%s", &N, a, b);
	
	for (int i = 0; i < N; i++)
		num[i] = 2 * (a[i] - '0') + (b[i] - '0');
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++)
			cnt[j][num[i]] += occ[j];
		occ[num[i]]++;
	}
	
	ll sol = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			int x = i / 2, y = i % 2;
			int z = j / 2, w = j % 2;
			if (x != z && !(y && w))
				sol += cnt[i][j];
		}
		
	printf("%lld\n", sol);
	
	return 0;
}