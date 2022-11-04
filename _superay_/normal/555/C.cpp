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
struct Node {
	int l, r, len_u, len_l;
	inline Node() {}
	inline Node(int _l, int _r, int _len_u, int _len_l): l(_l), r(_r), len_u(_len_u), len_l(_len_l) {}
	inline bool operator < (const Node &oth) const {
		return l < oth.l;
	}
};
int n, q;
set<Node> st;
int main() {
	scanf("%d%d", &n, &q);
	st.insert(Node(1, n, 0, 0));
	while (q--) {
		int x;
		char ty;
		scanf("%d%*d %c", &x, &ty);
		auto it = st.lower_bound(Node(x + 1, 0, 0, 0));
		if (it == st.begin()) { puts("0"); continue; }
		--it;
		Node cur = *it;
		if (!(cur.l <= x && x <= cur.r)) { puts("0"); continue; }
		st.erase(it);
		if (ty == 'U') {
			printf("%d\n", cur.len_u + cur.r - x + 1);
			if (cur.l < x) {
				st.insert(Node(cur.l, x - 1, cur.len_u + cur.r - x + 1, cur.len_l));
			}
			if (cur.r > x) {
				st.insert(Node(x + 1, cur.r, cur.len_u, 0));
			}
		} else {
			printf("%d\n", cur.len_l + x - cur.l + 1);
			if (cur.l < x) {
				st.insert(Node(cur.l, x - 1, 0, cur.len_l));
			}
			if (cur.r > x) {
				st.insert(Node(x + 1, cur.r, cur.len_u, cur.len_l + x - cur.l + 1));
			}
		}
	}
	return 0;
}