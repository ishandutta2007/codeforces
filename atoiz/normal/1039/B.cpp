#include <iostream>
#include <vector>
#include <cstdio>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

mt19937_64 rng((long long) duration_cast<milliseconds>(system_clock().now().time_since_epoch()).count());
uniform_int_distribution <mt19937_64::result_type> random(1, 1e18);

long long randint(long long from, long long to)
{
    return from + random(rng) % (to - from + 1);
}

bool ask(long long l, long long r)
{
	cout << l << ' ' << r << endl;
    string ans; cin >> ans;
    if (l == r && ans == "Yes") exit(0);
    return (ans == "Yes");
}

int main()
{
	long long n, k; cin >> n >> k;
    long long l = 1, r = n;
    while (true) {
        long long m = (l + r) >> 1;

        if (r - l <= 50) {
			long long wonder = randint(l, r);
			ask(wonder, wonder);
        } else {
			if (ask(l, m)) r = m;
			else l = m+1;
        }
		l = max(1ll, l-k);
		r = min(n, r+k);
	}
}