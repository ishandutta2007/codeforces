# include <map>
# include <cstdio>
# include <cstring>
# include <algorithm>
# include <iostream>
# define ll long long
using namespace std;
const int NR = 100051;
struct Tree{
	int s;
	int ls, rs;
} t[NR * 40 * 2];
int q, tsz, asz;
int rt1[NR], rt2[NR];
char op[31], a[31];
map <string, int> mp;
void update(int nw){
	t[nw].s = t[t[nw].ls].s + t[t[nw].rs].s;
}
int modify(int nw, int lft, int rgt, int pos, int nm){
	int newn = ++tsz;
	t[newn] = t[nw];
	if (lft == rgt){
		t[newn].s += nm;
		return newn;
	}
	int mid = (lft + rgt) >> 1;
	if (pos <= mid) t[newn].ls = modify(t[nw].ls, lft, mid, pos, nm);
	else t[newn].rs = modify(t[nw].rs, mid + 1, rgt, pos, nm);
	update(newn);
	return newn;
}
int getsum(int nw, int lft, int rgt, int l, int r){
	if (!nw) return 0;
	if (lft == l && rgt == r) return t[nw].s;
	int mid = (lft + rgt) >> 1, ans = 0;
	if (l <= mid && t[nw].ls) ans += getsum(t[nw].ls, lft, mid, l, min(r, mid));
	if (r >= mid + 1 && t[nw].rs) ans += getsum(t[nw].rs, mid + 1, rgt, max(l, mid + 1), r);
	return ans;
}
int main(){
	scanf("%d", &q);
	while (q--){
		int x;
		scanf("%s", op + 1);
		rt1[q] = rt1[q + 1];
		rt2[q] = rt2[q + 1];
		if (strcmp(op + 1, "set") == 0){
			scanf("%s", a + 1);
			scanf("%d", &x);
			int pos, w = 0;
			if (mp.find(a + 1) != mp.end()){
				pos = mp[a + 1];
				w = getsum(rt2[q], 1, 100000, pos, pos);
				if (w != 0) rt1[q] = modify(rt1[q], 1, 1000000000, w, -1);
			} else {
				mp[a + 1] = ++asz;
				pos = asz;
			}
			rt1[q] = modify(rt1[q], 1, 1000000000, x, 1);
			rt2[q] = modify(rt2[q], 1, 100000, pos, x - w);
		} else if (strcmp(op + 1, "query") == 0){
			scanf("%s", a + 1);
			if (mp.find(a + 1) == mp.end()){
				printf("-1\n");
				fflush(stdout);
				continue;
			}
			int pos = mp[a + 1];
			x = getsum(rt2[q], 1, 100000, pos, pos);
			if (x == 0){
				printf("-1\n");
				fflush(stdout);
				continue;
			}
			int ans = getsum(rt1[q], 1, 1000000000, 1, x - 1);
			printf("%d\n", ans);
			fflush(stdout);
		} else if (strcmp(op + 1, "remove") == 0){
			scanf("%s", a + 1);
			if (mp.find(a + 1) == mp.end()) continue;
			int pos = mp[a + 1];
			x = getsum(rt2[q], 1, 100000, pos, pos);
			if (x == 0) continue;
			rt2[q] = modify(rt2[q], 1, 100000, pos, -x);
			rt1[q] = modify(rt1[q], 1, 1000000000, x, -1);
		} else {
			scanf("%d", &x);
			rt1[q] = rt1[q + x + 1];
			rt2[q] = rt2[q + x + 1];
		}
	}
	return 0;
}