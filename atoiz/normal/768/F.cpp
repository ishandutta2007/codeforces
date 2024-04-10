#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long ll;
#define int long long

const ll MAX = 220005, MOD = 1e9 + 7;
ll fact[MAX + 1], invFact[MAX + 1];
ll powMod(ll a, ll p)
{
    ll res = 1;
    while (p > 0) {
		if (p & 1) res = res * a % MOD;
        p >>= 1;
        a = a * a % MOD;
    }
    return res;
}
void init()
{
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= MAX; ++i) {
		fact[i] = fact[i-1] * i % MOD;
        invFact[i] = powMod(fact[i], MOD - 2);
    }
}
ll comb(ll n, ll k)
{
	if (n < 0 || k < 0 || n < k) return 0;
	return fact[n] * invFact[n-k] % MOD * invFact[k] % MOD;
}

ll f, w, h;

void update(int f_b, int w_b, ll& newP, ll& newQ)
{
	newP = 0; newQ = 0;
    if (f_b > f || w_b > w) return;
    if (f_b == 0) {
		if (f > 0) {
			newP = newQ = 0;
			return;
		}
        newP = (w > h ? 1 : 0);
        newQ = 1;
        return;
    }
	if (w_b == 0) {
		if (w > 0) {
			newP = newQ = 0;
			return;
		}
		newP = 1;
		newQ = 1;
		return;
	}

    ll fCount = comb(f - 1, f_b - 1);
    newQ = fCount * comb(w - 1, w_b - 1) % MOD;
    newP = fCount * comb(w - (h) * w_b - 1, w_b - 1) % MOD;
//    if (f_b == 1 && w_b == 2) cout << fCount << ' ' << newP << ' ' << newQ << endl;
//    if (f_b == 1 && w_b == 2) cout << w << ' ' << h << ' ' << w_b << endl;
}

signed main()
{
	init();
//	cout << powMod(2, MOD - 2) << endl;
    cin >> f >> w >> h;
    ll p = 0, q = 0;
    for (int f_b = 0; f_b <= f; ++f_b) {
        ll newP, newQ;

        // w_b = f_b - 1
        if (f_b > 0) {
            update(f_b, f_b - 1, newP, newQ);
            p = (p + newP) % MOD;
            q = (q + newQ) % MOD;
        }

        // w_b = f_b
        update(f_b, f_b, newP, newQ);
        p = (p + 2 * newP) % MOD;
        q = (q + 2 * newQ) % MOD;

        // w_b = f_b + 1
        update(f_b, f_b + 1, newP, newQ);
//        cout << f_b << ' ' << f_b + 1 << ' ' << newP << ' ' << newQ << endl;
        p = (p + newP) % MOD;
        q = (q + newQ) % MOD;
    }

//    cout << p << ' ' << q << endl;
	cout << (p * powMod(q, MOD - 2) % MOD) << endl;
}