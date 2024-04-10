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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;

int n, k;
vector < pair < int, int > > event;
long long fact[N];
long long rfact[N];

long long rev(long long a, long long m) {
	if (a == 0) return 0;
	return ((1 - rev(m % a, a) * m) / a + m) % m;
}

long long getC(int n, int k) {
	return fact[n] * rfact[k] % MOD * rfact[n - k] % MOD;
}

void read() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		event.pb(mp(l, 1));
		event.pb(mp(r + 1, -1));
	}	
	sort(event.begin(), event.end());
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = (fact[i - 1] * i) % MOD;

	rfact[n] = rev(fact[n], MOD);
	//db2(fact[n - 1], fact[n - 1] * ((rfact[n] * n) % MOD) % MOD);
	for (int i = n - 1; i >= 0; i--)
		rfact[i] = (rfact[i + 1] * (i + 1)) % MOD;
	//for (int i = 0; i <= n; i++)
		//db3(fact[i], rfact[i], fact[i] * rfact[i] % MOD);
	//db2(rev(17, MOD), rev(17, MOD) * 1ll * 17 % MOD);

	//db(getC(5, 3));
	long long answer = 0;
	int cnt = 0;
	int last = 0;
	for (auto x: event) {
		if (cnt >= k) {
			answer = (answer + (x.fr - last) * 1ll * getC(cnt, k)) % MOD;
		}
		cnt += x.sc;
		last = x.fr;
	}
	
	printf("%lld\n", answer);
}

void solve() {

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