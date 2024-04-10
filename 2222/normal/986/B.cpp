#include <bits/stdc++.h>

#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (decltype(a) i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<int> p(n);
    vector<bool> u(n);
    int parity = 0;
    int k = 0;
    REP (i, n) {
        cin >> p[i];
        --p[i];
        if (p[i] == i) ++k;
    }
    REP (i, n) {
        if (u[i]) continue;
        int m = 0;
        for (int j = i; !u[j]; j = p[j]) {
            u[j] = true;
            ++m;
        }
        parity ^= (m + 1) % 2;
    }
    if (parity == (n % 2)) {
        cout << "Petr" << endl;
    } else {
        cout << "Um_nik" << endl;
    }
    return 0;
}