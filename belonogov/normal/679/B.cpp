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
const int N = 3e7 + 10;
const long long INF = 1e9 + 19;

long long n;

void read() {
	cin >> n; 
}

pair < int, long long > solve(long long x) {	
	int T = 64;
	if (x < T) {
		vector < int > f(T + 1);
		for (int i = 1; i < T; i++) {
			int j = 1;
			for (j = 1; (j + 1) * (j + 1) * (j + 1) <= i; j++);
			f[i] = f[i - j * j * j] + 1;
		}
		int pos = 0;
		for (int i = x; i >= 1; i--)
			if (f[i] > f[pos])
				pos = i;
		return mp(f[pos], pos);
	}
	long long j = 1;	
	for (j = 1; (j + 1) * (j + 1) * (j + 1) <= x; j++);

	auto r1 = solve(x - j * j * j);	
	auto r2 = solve(j * j * j - (j - 1) * (j - 1) * (j - 1) - 1);	
	r1.fr++;
	r1.sc += j * j * j;
	r2.fr++;
	r2.sc += (j - 1) * (j - 1) * (j - 1);

	return max(r1, r2);	
}

vector < pair < int, long long > > stupid(int n) {
	vector < int > f(n + 1, 0);
	vector < pair < int, long long > > g(1);
	int pos = 0;
	for (int i = 1; i <= n; i++) {
		int j = 1;
		for (j = 1; (j + 1) * (j + 1) * (j + 1) <= i; j++);
		f[i] = f[i - j * j * j] + 1;
		if (f[i] >= f[pos]) 
			pos = i; 
		g.pb(mp(f[pos], pos));
	}
	return g;
}


void printAns(pair < int, long long > tmp) {
	cout << tmp.fr << " " << tmp.sc << endl;
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
            printAns(solve(n));
        }
    }
    else {
		int n = 1e6;
		auto r2 = stupid(n);
		for (int i = 1; i < n; i++) {
			if (i % 10000 == 0) db(i);
			auto r1 = solve(i);
			//cerr << endl;
			//db2(r1.fr, r1.sc);
			//db2(r2[i].fr, r2[i].sc);
			assert(r1 == r2[i]);


			//db2(r1.fr, r1.sc);
			//db2(r2.fr, r2.sc);
			//assert(r1 == r2);
			//db2(i, "OK");
		}
    }

    return 0;
}