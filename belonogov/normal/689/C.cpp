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
const int N = -1;
const long long INF = 1e9 + 19;


long long m;

void read() {
	scanf("%lld", &m);
}

long long check(long long n) {
	long long sum = 0;
	for (long long k = 2; ; k++) {
		if (sum > m) return sum;

		long long tmp = n / (k * k * k);
		if (tmp == 0) break;
		sum += tmp;
	}
	return sum;
}

void solve() {
	long long l = 0;
	long long r = m * 10;
	while (r - l > 1) {
		if (check((l + r) / 2) < m) 
			l = (l + r) / 2;
		else
			r = (l + r) / 2;
	}
	if (check(r) == m) {
		printf("%lld\n", r);
	}
	else
		puts("-1");
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