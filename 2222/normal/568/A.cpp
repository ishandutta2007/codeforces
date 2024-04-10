#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

vector<bool> primes(10000000);

int main() {
    int num, denum;
    cin >> num >> denum;
    for (int i = 2; i * i < primes.size(); ++i)
        if (!primes[i]) {
            for (int j = i * i; j < primes.size(); j += i)
                primes[j] = true;
        }
    primes[1] = true;
    int res = 0, pr = 0, pa = 0;
    for (int x = 1; x < primes.size(); ++x) {
        if (!primes[x])
            ++pr;
        int y = 0;
        for (int z = x; z; z /= 10)
            y = y * 10 + (z % 10);
        if (x == y)
            ++pa;
        if (pr * (ll)denum <= pa * (ll)num) {
            res = x;
        }
    }
    cout << res << endl;
    return 0;
}