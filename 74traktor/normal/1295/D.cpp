#include<bits/stdc++.h>

using namespace std;

#define int long long

vector < int > t;
int R, ans;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        int c = a % b;
        a = b, b = c;
    }
    return a + b;
}

inline int solve(int r, int x) {
    int i = 2;
    if (r == 0) return 0;
    if (x == 1) return r;
    t = {};
    while (i * i <= x) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (cnt > 0) t.push_back(i);
        ++i;
    }
    if (x != 1) t.push_back(x);
    ans = r;
    int N = (int)t.size();
    for (int mask = 1; mask < (1 << N); ++mask) {
        int go = 1, cnt = 0;
        for (int j = 0; j < N; ++j) {
            if ((mask&(1 << j)) > 0) {
                cnt++;
                go *= t[j];
            }
        }
        if (cnt % 2 == 1) ans -= r / go;
        else ans += r / go;
    }
    return ans;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    //cout << solve(12, 9) << '\n';
    //return 0;
    while (t--) {
        int a, m;
        cin >> a >> m;
        int x = gcd(a, m);
        int ans = (m - 1) / x;
        int A = a / x, B = m / x;
        //if (t == 0) break;
        //cout << A << " " << A + ans << " " << B << '\n';
        cout << solve(A + ans, B) - solve(A - 1, B) << '\n';
    }
    return 0;
}