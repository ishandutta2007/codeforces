#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 5555;
const long long INF = 1e9 + 19;

struct pt {
	long long x, y;
	pt () { }
	pt (long long x, long long y): x(x), y(y) { }
	pt operator + (pt A) {
		return pt(x + A.x, y + A.y);
	}
	pt operator - (pt A) {
		return pt(x - A.x, y - A.y);
	}
	long long operator * (pt A) {
		return x * A.y - y * A.x;
	}
	long long operator % (pt A) {
		return x * A.x + y * A.y;
	}
	long long len2() {
		return x * x + y * y;
	}
	pt rotate() {
		return pt(-y, x);
	}
	void print() {
		printf("%lld %lld\n", x, y);
	}
};

int n;
pt p[N];
pt st[N];

void read() {
	long long g;
	scanf("%d%lld", &n, &g);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &p[i].x, &p[i].y);
}

void convexHull() {
	for (int i = 0; i < n; i++)
		if (p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x))
			swap(p[i], p[0]);
	pt O = p[0];
	sort(p + 1, p + n, [=](pt A, pt B) {
				A = A - O;
				B = B - O;
				return (A * B > 0 || (A * B == 0 && A.len2() < B.len2()));
			});
	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (; cur >= 2 && (st[cur - 1] - st[cur - 2]) * (p[i] - st[cur - 1]) <= 0; cur--);
		st[cur++] = p[i];	
	}
	for (int i = 0; i < n; i++)
		p[i] = st[i];
	n = cur;
}

long long getS(pt A, pt B, pt C) {
	return (B - A) * (C - A);
}

void solve() {
	convexHull();
	pt A, B, C;
	A = p[0];
	B = p[1];
	C = p[2];	
	for (int i = 0; i < n; i++) {
		int cur = i + 1;
		for (int j = i + 1; j < n; j++) {
			cur = max(cur, j + 1);
			for (; cur + 1 < n && getS(p[i], p[j], p[cur + 1]) > getS(p[i], p[j], p[cur]); cur++);
			if (getS(A, B, C) < getS(p[i], p[j], p[cur])) {
				A = p[i];
				B = p[j];
				C = p[cur];
			}
		}
	}
	pt D, E, F;
	D = A + (C - B);
	F = C + (B - A);
	E = B + (A - C);

	D.print();
	E.print();
	F.print();



}

void stress() {

}

int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}