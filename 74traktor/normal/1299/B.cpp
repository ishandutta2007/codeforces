#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int x[maxn], y[maxn];

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        int c = a % b;
        a = b, b = c;
    }
    return a + b;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector < vector < int > > Q;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    if (n % 2 == 0) {
        for (int i = 1; i <= n; ++i) {
            int nxt = (i + 1);
            if (nxt > n) nxt -= n;
            int A = y[i] - y[nxt], B = x[nxt] - x[i];
            int s = gcd(abs(A), abs(B));
            A /= s, B /= s;
            if (A != 0) {
                if (A < 0) A *= (-1), B *= (-1);
            }
            else {
                if (B < 0) B *= (-1);
            }
            Q.push_back({A, B, s * s * (A * A + B * B)});
        }
        sort(Q.begin(), Q.end());
        for (int i = 0; i < (int)Q.size(); i += 2) {
            if (Q[i] != Q[i + 1]) {
                cout << "NO" << '\n';
                return 0;
            }
        }
        cout << "YES";
    }
    else {
        cout << "NO" << '\n';
        return 0;
    }
    return 0;
}