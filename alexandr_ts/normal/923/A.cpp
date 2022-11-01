#include <bits/stdc++.h>
using namespace std;

#define TASKNAME "a"
void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
#define pb push_back
#define fi first
#define se second

template<typename T>
ostream& operator << (ostream &fo, vector<T> v) {
    fo << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        fo << v[i] << " ";
    }
    fo << "] ";
    return fo;
}

template<typename T1, typename T2>
ostream& operator << (ostream &fo, pair<T1, T2> p) {
    fo << "(" << p.first << ", " << p.second << ") ";
    return fo;
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;

vector<int> p;

int go(int x) {
    int y = N;
    for (auto pr: p) {
        if (x % pr == 0) {
            y = min(y, x - pr + 1);
        }
    }
    return y;
}


int dp[N], dp2[N];
void cnt1(int x) {
    int y = x;
    int xx = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        y = min(y, xx - i + 1);
        while (x % i == 0) {
            x /= i;
        }
    }
    if (x > 1 && x != xx) {
        y = min(y, xx - x + 1);
    }
    dp[xx] = y;
}

int cnt2(int x) {
    int ps = dp[x];
    int y = N;
    for (int i = ps; i < x; i++) {
        y = min(y, dp[i]);
    }
    return y;
}

void solve() {
    int x;
    cin >> x;
    cout << cnt2(x) << "\n";
}

int main() {
    init();
    for (int i = 0; i < N; i++) cnt1(i);

    solve();
    //solve();
    //solve();

    return 0;
}