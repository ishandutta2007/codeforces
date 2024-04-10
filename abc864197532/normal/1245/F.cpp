#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second

map <pair <int, int>, long long> m1;

long long solve(int a, int b) {
    if (a > b) swap(a, b);
    if (a < 0) return 0;
    if (a == 0) return b + 1;
    if (m1.count({a, b})) return m1[{a, b}];
    int i = 30;
    while (i >= 0) {
        if (a & (1 << i) or b & (1 << i)) break;
        i--;
    }
    long long ans = 0;
    // 0 0
    ans += solve(min((1 << i) - 1, a), min((1 << i) - 1, b));
    // 1 0
    if (a & (1 << i)) ans += solve(a ^ (1 << i), min((1 << i) - 1, b));
    // 0 1
    if (b & (1 << i)) ans += solve(min((1 << i) - 1, a), b ^ (1 << i));
    return m1[{a, b}] = ans;
}

int main () {
    int t, x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        cout << solve(y, y) - solve(x - 1, y) * 2 + solve(x - 1, x - 1) << endl;
    }
}