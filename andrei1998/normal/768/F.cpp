#include <iostream>

using namespace std;

const int NMAX = 3 * 100000 + 15;
const int MOD = 1000000000 + 7;

int N;

int raise(int a, int b) {
    if (!b)
        return 1;
    else if (b & 1)
        return (1LL * a * raise(a, b - 1)) % MOD;
    else {
        int aux = raise(a, b >> 1);
        return (1LL * aux * aux) % MOD;
    }
}

int inv(int nr) {
    return raise(nr, MOD - 2);
}

int facts[NMAX];
int invFacts[NMAX];

void precalcFacts() {
    facts[0] = 1;
    for (int i = 1; i < NMAX; ++ i)
        facts[i] = (1LL * i * facts[i - 1]) % MOD;

    invFacts[NMAX - 1] = inv(facts[NMAX - 1]);
    for (int i = NMAX - 2; i >= 0; -- i)
        invFacts[i] = ((i + 1LL) * invFacts[i + 1]) % MOD;
}

inline int choose(int n, int k) {
    return ((1LL * facts[n] * invFacts[k]) % MOD * invFacts[n - k]) % MOD;
}

inline int cnt(int stacks, int objs, int atLeast = 1) {
    if (objs - 1LL * atLeast * stacks < 0)
        return 0;
    objs -= atLeast * stacks;

    if (objs == 0 && stacks == 0)
        return 1;
    return choose(objs + stacks - 1, stacks - 1);
}

int main()
{
    precalcFacts();

    int f, w, h;
    cin >> f >> w >> h;

    int A = 0;
    int B = 0;
    for (int stkF = 0; stkF <= f; ++ stkF) {
        for (int stkW = stkF - 1; stkW <= w && stkW <= stkF + 1; ++ stkW)
            if (stkW >= 0) {
                if (stkF != stkW) {
                    A = (A + 1LL * cnt(stkF, f) * cnt(stkW, w, h + 1)) % MOD;
                    B = (B + 1LL * cnt(stkF, f) * cnt(stkW, w)) % MOD;
                }
                else {
                    A = (A + 2LL * cnt(stkF, f) * cnt(stkW, w, h + 1)) % MOD;
                    B = (B + 2LL * cnt(stkF, f) * cnt(stkW, w)) % MOD;
                }
            }
    }

    int ans = (1LL * A * inv(B)) % MOD;
    cout << ans << '\n';
    return 0;
}