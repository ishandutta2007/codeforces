#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

#define mp make_pair
#define M 2005
#define inf (lint)1e17

struct data {
	lint dist, id;
	data (lint _d, lint _id) {
		dist = _d, id = _id;
	} data () {}
};

lint n, i, j, a, b, c, d, p, q, r, s; 
data D1[M], D2[M]; bool Mark[M];

void Debug (data A[]) {
	lint k;
	for (k = 1; k <= n; k++) cout << A[k].id << " " << A[k].dist << endl;
	cout << endl;
}

lint SqDist (lint p, lint q, lint r, lint s) {
	return (p - r) * (p - r) + (q - s) * (q - s);
}

bool cmp (data A, data B) {
	return A.dist < B.dist;
}

int main() {
	memset(Mark, 0, sizeof Mark);
	cin >> n >> a >> b >> c >> d;
	for (i = 1; i <= n; i++) {
		cin >> p >> q;
		D1[i].id = D2[i].id = i;
		D1[i].dist = SqDist(a, b, p, q);
		D2[i].dist = SqDist(c, d, p, q);
	}
	sort (D1 + 1, D1 + 1 + n, cmp);
	sort (D2 + 1, D2 + 1 + n, cmp);
	lint Ret = inf, mx;
	for (i = 1; i <= n; i++) {
		Mark[D1[i].id] = 1; mx = 0;
		for (j = 1; j <= n; j++)
			if (!Mark[D2[j].id]) mx = max(mx, D2[j].dist);
		Ret = min(Ret, mx + D1[i].dist);
	}
	Ret = min(Ret, D1[n].dist); Ret = min(Ret, D2[n].dist);
	cout << Ret << endl;
	return 0;
}