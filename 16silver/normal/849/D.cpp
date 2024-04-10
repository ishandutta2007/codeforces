#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class stt {
public:
	int sub;
	int pl;
	int idx;
};
int compare(const stt &x, const stt &y) {
	if (x.sub > y.sub) return 1;
	else if (x.sub < y.sub) return 0;
	else {
		if (x.pl > y.pl) return 1;
		else return 0;
	}
}
int g[100000], p[100000], t[100000], ans[100000][2], dst[100000][2];
stt q[100000], qq[100000];
int main() {
	int n, w, h, i;
	scanf("%d %d %d", &n, &w, &h);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &g[i], &p[i], &t[i]);
		q[i].idx = i;
		q[i].sub = t[i] - p[i];
		if (g[i] == 1) q[i].pl = w - p[i];
		else q[i].pl = w + p[i];
		qq[i].idx = i;
		qq[i].sub = t[i] - p[i];
		if (g[i] == 1) qq[i].pl = h + w - p[i];
		else qq[i].pl = p[i];
		if (g[i] == 1) {
			dst[i][0] = p[i];
			dst[i][1] = h;
		}
		else {
			dst[i][0] = w;
			dst[i][1] = p[i];
		}
	}
	sort(q, q + n, compare);
	sort(qq, qq + n, compare);
	for (i = 0; i < n; i++) {
		ans[q[i].idx][0] = dst[qq[i].idx][0];
		ans[q[i].idx][1] = dst[qq[i].idx][1];
	}
	for (i = 0; i < n; i++) {
		printf("%d %d\n", ans[i][0], ans[i][1]);
	}
}