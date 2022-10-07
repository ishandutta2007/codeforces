#include <cstdio>
int n;
int query(int x1, int y1, int x2, int y2){
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int s;
	scanf("%d", &s);
	return s;
}
int solve1(int c){
	int l = 1, r = n, md;
	while (l < r) if (query(l, c, md = (l + r) >> 1, c) & 1) r = md; else l = md + 1;
	return l;
}
int solve2(int c){
	int l = 1, r = n, md;
	while (l < r) if (query(c, l, c, md = (l + r) >> 1) & 1) r = md; else l = md + 1;
	return l;
}
int main(){
	scanf("%d", &n);
	int now = 0, l = 0, r = 0;
	for (register int i = 1; i < n; ++i){
		int x = query(1, i, n, i);
		if (x & 1) l ? r = i : l = i;
		now = x - now;
	}
	if (now & 1) l ? r = n : l = n;
	if (l) printf("! %d %d %d %d\n", solve1(l), l, solve1(r), r);
	else{
		int now = 0, l = 0, r = 0;
		for (register int i = 1; i < n; ++i){
			int x = query(i, 1, i, n);
			if (x & 1) l ? r = i : l = i;
			now = x - now;
		}
		if (now & 1) l ? r = n : l = n;
		now = solve2(l), printf("! %d %d %d %d\n", l, now, r, now);
	}
	fflush(stdout);
}