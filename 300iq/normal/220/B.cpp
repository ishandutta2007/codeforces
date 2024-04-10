#include <bits/stdc++.h>

#define pi 3.141592653589793238462643383279
#define kill abacaba
#define mp make_pair
#define fc first
#define sc second

using namespace std;

typedef long long ll;

const int MAXN = 1000000 + 7, MAXM = 100000;
int BLOCK_SIZE;

int cur_l, cur_r, l, r, n, q, i;
int answer[MAXM], a[MAXM], cnt[MAXN];
int ans = 0;

struct quer {
	int a, b, c;
} e[MAXM];


inline void add(int x) {
    if (x > 100000) {
        return;
    }
    if (x == cnt[x]) {
        ans--;
    }
	cnt[x]++;
	if (x == cnt[x]) {
		ans++;
	}
}

inline void rem(int x) {
    if (x > 100000) {
        return;
    }
	if (x == cnt[x]) {
        ans--;
    }
    cnt[x]--;
    if (x == cnt[x]) {
        ans++;
    }
}

inline bool cmp(quer a, quer b) {
	l = a.a / BLOCK_SIZE, r = b.a / BLOCK_SIZE;
	return (l == r ? a.b < b.b : l < r);
}

inline int nextInt() {
	char c = getchar();
	while (c <= 32) {
		c = getchar();
	}
	int t = 0;
	while (c > 32) {
		t = (t << 1) + (t << 3) + c - 48;
		c = getchar();
	}
	return t;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);	
    n = nextInt(), q = nextInt();
    for (i = 0; i < n; i++) {
    	a[i] = nextInt();
    }
    cur_l = 0, cur_r = 0;
    add(a[0]);
    BLOCK_SIZE = 500;
    for (i = 0; i < q; i++) {
    	e[i].a = nextInt(), e[i].b = nextInt();
    	e[i].a--, e[i].b--;
    	e[i].c = i;
    }
    sort(e, e + q, cmp);
    for (i = 0; i < q; i++) {
    	l = e[i].a;
    	r = e[i].b;
    	while (cur_l > l) {
    		cur_l--;
    		add(a[cur_l]);
    	}
    	while (cur_r < r) {
    		cur_r++;
    		add(a[cur_r]);
    	}
    	while (cur_l < l) {
    		rem(a[cur_l]);
    		cur_l++;
    	}
    	while (cur_r > r) {
    		rem(a[cur_r]);
    		cur_r--;
    	}
       	answer[e[i].c] = ans;
    }
    for (i = 0; i < q; i++) {
    	printf("%d\n", answer[i]);
    }
}