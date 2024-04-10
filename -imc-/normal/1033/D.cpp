#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool);

void sieve();

int main() {
#ifdef YA
    auto s = clock();
    assert(freopen("input.txt", "r", stdin));
#else
    //assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << fixed << setprecision(20);

    sieve();

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

bool isPrime(li x) {
    for (li y = 2; y * y <= x; ++y) {
        if (x % y == 0) {
            return false;
        }
    }

    return true;
}

const int maxN = 2e6;
bool isNotPrime[maxN];
vector<int> primes;

void sieve() {
    for (int p = 2; p < maxN; ++p) {
        if (!isNotPrime[p]) {
            primes.push_back(p);

            for (li j = p * (li)p; j < maxN; j += p) {
                isNotPrime[j] = true;
            }
        }
    }
}

using factorization = map<int, int>;

pair<li, bool> getRoot(li x, int power) {
    assert(power >= 2 && power <= 4);
    li low = 1, high = (power == 2 ? 2e9 + 100 : (power == 3 ? 1259921 + 100 : 37606 + 100));

    auto getPower = [&](li m) {
        li prod = 1;
        for (int k = 0; k < power; ++k) {
            prod *= m;
        }
        return prod;
    };

    //cout << x << " " << getPower(high) << endl;
    assert(getPower(high) > x);

    while (low + 1 != high) {
        li m = (low + high) / 2;

        if (getPower(m) > x) {
            high = m;
        } else {
            low = m;
        }
    }

    //cout << "root " << low << " power " << getPower(low) << "\n";

    if (getPower(low) == x) {
        return make_pair(low, true);
    } else {
        return make_pair(0, false);
    }
}

void solve(__attribute__((unused)) bool read) {

    int n;
    if (read) {
        cin >> n;
    } else {
        n = rand() % 100 + 1;
    }

    factorization secretFac;

    vector<li> a(n);
    vector<factorization> full;

    vector<li> pqExp;

    vector<li> quadraticPrimes, cubicPrimes, quadPrimes;
    if (!read) {
        for (int t = 1e9 * 1.4; quadraticPrimes.size() < 10; --t) {
            if (isPrime(t)) {
                quadraticPrimes.push_back(t);
            }
        }
        for (int t = 1e6 * powl(2, 1.0 / 3); cubicPrimes.size() < 10; --t) {
            if (isPrime(t)) {
                cubicPrimes.push_back(t);
            }
        }
        for (int t = powl(1e18, 1.0 / 4); quadPrimes.size() < 10; --t) {
            if (isPrime(t)) {
                quadPrimes.push_back(t);
            }
        }
    }

    vector<li> pqNumbers;
    for (int i = 0; i < n; ++i) {
        if (read) {
            cin >> a[i];
        } else {
            int t = rand() % 5;

            li p = primes[rand() % 10];

            factorization f;
            if (t == 0) {
                p = quadraticPrimes[rand() % quadraticPrimes.size()];
                a[i] = p * p;
                f[p] = 2;
            } else if (t == 1) {
                p = cubicPrimes[rand() % cubicPrimes.size()];
                a[i] = p * p * p;
                f[p] = 3;
            } else if (t == 2) {
                p = quadPrimes[rand() % quadPrimes.size()];
                a[i] = p * p * p * p;
                f[p] = 4;
            } else if (t == 3 || t == 4) {
                if (t == 3) {
                    p = quadraticPrimes[rand() % quadraticPrimes.size()];
                } else {
                    p = cubicPrimes[rand() % cubicPrimes.size()];
                }

                li q = 0;
                do {
                    if (t == 3) {
                        q = quadraticPrimes[rand() % quadraticPrimes.size()];
                    } else {
                        q = cubicPrimes[rand() % cubicPrimes.size()];
                    }
                    q = primes[rand() % 1000];
                } while (p == q);

                if (t == 3) {
                    a[i] = p * q;
                    f[p] = 1;
                    f[q] = 1;
                    pqExp.push_back(p * q);
                } else {
                    a[i] = p * q * q;
                    f[p] = 1;
                    f[q] = 2;
                }
            }

            //cout << "factorization ";
            for (auto it : f) {
                secretFac[it.first] += it.second;
                /*for (int i = 0; i < it.second; ++i) {
                    cout << it.first << " ";
                }*/
            }
            //cout << "\n";
        }

        bool found = false;

        for (int t = 2; t >= 0; --t) {
            auto p = getRoot(a[i], 2 + t);

            if (p.second) {
                factorization f;
                f[p.first] = t + 2;
                //cout << "factorized " << a[i] << " as power " << p.first << " " << t + 2 << endl;
                full.push_back(f);
                found = true;
                break;
            }
        }

        if (found) {
            continue;
        }

        for (int p : primes) {
            if (a[i] % p == 0) {
                factorization f;
                if (a[i] % (p * (li)p) == 0) {
                    f[p] = 2;
                    f[a[i] / p / p] = 1;
                    assert(a[i] / p / p > 1 && a[i] / p / p != p);
                    full.push_back(f);
                    found = true;
                } else {
                    f[p] = 1;

                    // p^2 q or pq case

                    auto P = getRoot(a[i] / p, 2);
                    if (P.second) {
                        assert(P.first != p);
                        f[P.first] = 2;
                        full.push_back(f);
                        found = true;
                    } else {
                        // pq case
                        break;
                    }
                }
                if (found) {
                    /*cout << "could factorize " << a[i] << endl;
                    for (auto it : full.back()) {
                        cout << it.first << " " << it.second << endl;
                    }
                    cout << "end" << endl;*/
                    break;
                }
            }
        }

        if (found) {
            continue;
        }

        pqNumbers.push_back(a[i]);
    }

    vector<li> primeCandidates;
    for (auto& it : full) {
        for (auto p : it) {
            primeCandidates.push_back(p.first);
        }
    }

#if 0
    for (auto it : pqNumbers) {
        cout << "pq num " << it << endl;
    }
#endif

    if (!read) {
        assert(pqNumbers == pqExp);
    }

    for (int i = 0; i < pqNumbers.size(); ++i) {
        for (int j = i + 1; j < pqNumbers.size(); ++j) {
            if (pqNumbers[i] == pqNumbers[j]) {
                continue;
            }

            li g = __gcd(pqNumbers[i], pqNumbers[j]);
            if (g != 1) {
                assert(g != pqNumbers[i]);
                assert(g != pqNumbers[j]);
                assert(pqNumbers[i] / g != pqNumbers[j] / g);
                assert(pqNumbers[i] / g != g);

                primeCandidates.push_back(g);
                primeCandidates.push_back(pqNumbers[i] / g);
                primeCandidates.push_back(pqNumbers[j] / g);
            }
        }
    }
    sort(all(primeCandidates));
    primeCandidates.erase(unique(all(primeCandidates)), primeCandidates.end());

    const li MOD = 998244353;
    li answer = 1;

#if 0
    cout << "watch pre-pq ";
    for (auto& it : full) {
        cout << "got ";
        for (auto p : it) {
            for (int i = 0; i < p.second; ++i) {
                cout << p.first << " ";
            }
        }
        cout << "\n";
    }
    cout << "end" << endl;
#endif

    map<li, int> failedFactors;

    for (li x : pqNumbers) {
        bool found = false;
        for (li y : primeCandidates) {
            if (y >= x) {
                continue;
            }

            if (x % y == 0) {
                factorization f;
                f[y] = 1;
                f[x / y] = 1;
                assert(x / y != y);
                full.push_back(f);
                found = true;
                break;
            }
        }

        if (!found) {
            //cout << "Failed to factor " << x << endl;
            ++failedFactors[x];
        }
    }

    for (auto it : failedFactors) {
        answer = answer * (it.second + 1) * (it.second + 1) % MOD;
    }

    factorization composite;
    for (auto& it : full) {
        //cout << "got ";
        for (auto p : it) {
            /*
            for (int i = 0; i < p.second; ++i) {
                cout << p.first << " ";
            }*/
            composite[p.first] += p.second;
        }
        //cout << "\n";
    }
    for (auto& p : composite) {
        //cout << "composite fac " << p.first << " " << p.second << endl;
        answer = answer * (p.second + 1) % MOD;
    }

    cout << answer << endl;

#if 0
    if (!read) {
        li expected = 1;
        for (auto p : secretFac) {
            expected = expected * (p.second + 1) % MOD;
        }

#if 0
        cout << "test:\n";
        cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
#endif

        cout << "answer: " << answer << ", expected: " << expected << endl;
        assert(answer == expected);
    }
#endif
}