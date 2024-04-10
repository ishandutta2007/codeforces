#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int l, r;

int b[10], ans;

int main() {
    scanf("%d%d", &l, &r);
    for (register int i = l; i <= r; i++) {
		memset(b, 0, sizeof(b));
		if (i > 99999) b[i/100000]++;
		if (i > 9999) b[i%100000/10000]++;
		if (i > 999) b[i%10000/1000]++;
		if (i > 99) b[i%1000/100]++;
		if (i > 9) b[i%100/10]++;
		b[i%10]++;
		int flag = 1;
		for (register int x = 0; x < 10; x++)
			if (b[x] > 1) flag = false;
		if (flag) { printf("%d", ans = i); break; }
    }
	if (!ans) printf("-1");
    return 0;
}