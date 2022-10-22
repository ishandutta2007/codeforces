
#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool);

int main() {
#ifdef YA
    auto s = clock();
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << fixed << setprecision(20);

    solve(true);

#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - s) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

//#define int li
//const int mod = 1000000007;

const int maxp = 15e6 + 100;
bool isNotPrime[maxp];
vector<int> primes;

void sieve() {
    for (int i = 2; i < maxp && i * i < maxp; ++i) {
        if (isNotPrime[i]) {
            continue;
        }

        for (int j = i * i; j < maxp; j += i) {
            isNotPrime[j] = true;
        }
    }

    for (int i = 2; i < maxp; ++i) {
        if (!isNotPrime[i]) {
            primes.push_back(i);
        }
    }
}

int cnt[maxp];

void solve(__attribute__((unused)) bool read) {
    sieve();
    //cout << "got " << primes.size() << endl;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int g = a[0];
    for (int i = 1; i < n; ++i) {
        g = __gcd(g, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        a[i] /= g;
        ++cnt[a[i]];
    }

    int answer = n;
    for (int p : primes) {
        int can = 0;
        for (int k = p; k < maxp; k += p) {
            can += cnt[k];
        }

        assert(can < n);
        answer = min(answer, n - can);
    }

    if (answer == n) {
        answer = -1;
    }
    cout << answer << endl;
}