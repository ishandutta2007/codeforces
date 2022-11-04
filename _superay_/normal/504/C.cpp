/*
                _____________   ______________       __
               / _________  /\ /_____   _____/\     / /\
              / /\       / /  \\    /  /\    \ \   / /  \
             / /  \_____/ /   / \__/  /  \____\/  / /   /
            / /   /    / /   /    /  /   /       / /   /
           / /   /    / /   /    /  /   /       / /   /
          / /   /    / /   /    /  /   /       / /   /
         / /___/____/ /   /    /  /   /       / /___/________
        /____________/   /    /__/   /       /______________/\
        \            \  /     \  \  /        \              \ \
         \____________\/       \__\/          \______________\/
           ___       ___      ___      ___    ______________
          /  /\     /  /\    /  /\    /  /\  /_____   _____/\
         /  /__\___/  /  \  /  /  \  /  /  \ \    /  /\    \ \
        /____    ____/   / /  /   / /  /   /  \__/  /  \____\/
        \   /   /\   \  / /  /_____/  /   /     /  /   /
         \_/   /  \___\/ /   _____   /   /     /  /   /
          /   /   /     /  /\    /  /   /     /  /   /
         /   /   /     /  /  \__/  /   /     /  /   /
        /___/   /     /__/   / /__/   /     /__/   /
        \   \  /      \  \  /  \  \  /      \  \  /
         \___\/        \__\/    \__\/        \__\/

          A FAN OF YHT

*/
/*
_/_/_/_/    _/_/_/_/_/  _/_/_/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/  _/  _/
_/      _/  _/  _/    _/    _/_/
_/_/_/_/      _/_/     _/_/_/_/_/

_/_/_/_/    _/    _/  _/      _/
_/      _/   _/  _/   _/_/  _/_/
_/      _/    _/_/    _/ _/_/ _/
_/      _/     _/     _/  _/  _/
_/      _/    _/_/    _/      _/
_/      _/   _/  _/   _/      _/
_/_/_/_/    _/    _/  _/      _/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/
% djq dxm
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, spe, a[N], ok[N], ty[N], cur[3], curs0;
namespace ST {
	int st[N * 4];
	void modify(int i, int l, int r, int pos, int x) {
		if (l == r) {
			st[i] += x;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) modify(i << 1, l, mid, pos, x);
		else modify(i << 1 | 1, mid + 1, r, pos, x);
		st[i] = min(st[i << 1], st[i << 1 | 1]);
	}
}
using ST::modify;
inline void Add(int pos) {
	int r = min(pos, n - pos + 1);
	cur[ty[r]]--;
	if (pos == n - pos + 1) {
		curs0 -= ok[r];
		ty[r] = 1;
		modify(1, 1, n, spe, -1);
		modify(1, 1, n, a[pos], 1);
	} else {
		ty[r]++;
		if (ty[r] == 1) {
			curs0 -= ok[r];
			modify(1, 1, n, a[pos], 1);
			modify(1, 1, n, a[n - pos + 1], -1);
		} else {
			modify(1, 1, n, a[pos], 2);
		}
	}
	cur[ty[r]]++;
}
inline void Del(int pos) {
	int r = min(pos, n - pos + 1);
	cur[ty[r]]--;
	if (pos == n - pos + 1) {
		curs0 += ok[r];
		ty[r] = 0;
		modify(1, 1, n, spe, 1);
		modify(1, 1, n, a[pos], -1);
	} else {
		ty[r]--;
		if (ty[r] == 0) {
			curs0 += ok[r];
			modify(1, 1, n, a[pos], -1);
			modify(1, 1, n, a[n - pos + 1], 1);
		} else {
			modify(1, 1, n, a[pos], -2);
		}
	}
	cur[ty[r]]++;
}
inline bool check(int l, int r) {
	if (l > r) return false;
	return cur[0] == curs0 && ST::st[1] >= 0;
}
int cnt[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[a[i]]++;
	spe = 0;
	if (n % 2 == 0) {
		for (int i = 1; i <= n; i++) if (cnt[i] & 1) {
			puts("0");
			return 0;
		}
		for (int i = 1; i <= n / 2; i++) ok[i] = (a[i] == a[n - i + 1]);
	} else {
		int flag = 0;
		for (int i = 1; i <= n; i++) if (cnt[i] & 1) {
			if (!flag) flag = 1, spe = i;
			else {
				puts("0");
				return 0;
			}
		}
		for (int i = 1; i <= n / 2; i++) ok[i] = (a[i] == a[n - i + 1]);
	}
	if (spe) ok[n / 2 + 1] = (a[n / 2 + 1] == spe);
	cur[0] = (n + 1) / 2;
	curs0 = 0;
	for (int i = 1; i <= (n + 1) / 2; i++) curs0 += ok[i];
	long long ans = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= n && !check(i, j - 1)) {
			Add(j);
			j++;
		}
		if (!check(i, j - 1)) break;
		ans += n - j + 2;
		Del(i);
	}
	printf("%lld\n", ans);
	return 0;
}