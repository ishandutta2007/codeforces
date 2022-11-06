#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };

const lint inf = 2000000000000000000LL;
lint f[111111];

char get(int n, lint k) {
    if (k >= f[n]) {
        return '.';
    }
    if (n == 0) {
        return "What are you doing at the end of the world? Are you busy? Will you save us?"[k];
    }
    if (k < (int) strlen("What are you doing while sending \"")) {
        return "What are you doing while sending \""[k];
    }
    k -= strlen("What are you doing while sending \"");
    if (k < f[n - 1]) {
        return get(n - 1, k);
    }
    k -= f[n - 1];
    if (k < (int) strlen("\"? Are you busy? Will you send \"")) {
        return "\"? Are you busy? Will you send \""[k];
    }
    k -= strlen("\"? Are you busy? Will you send \"");
    if (k < f[n - 1]) {
        return get(n - 1, k);
    }
    k -= f[n - 1];
    assert(k <= 1);
    return "\"?"[k];
}

void solve(istream& cin, ostream& cout) {
    f[0] = strlen("What are you doing at the end of the world? Are you busy? Will you save us?");
    rep(i, 1, 111111) {
        f[i] = strlen("What are you doing while sending \"") + f[i - 1] + strlen("\"? Are you busy? Will you send \"") + f[i - 1] + 2;
        f[i] = min(f[i], inf);
    }
    int q;
    cin >> q;
    rep(iq, 0, q) {
        int n;
        lint k;
        cin >> n >> k;
        cout << get(n, k - 1);
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}