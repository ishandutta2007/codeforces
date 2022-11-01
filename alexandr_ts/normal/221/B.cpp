#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 2e5;
const int INF = 2e9;

int check(int a, int b) {
    string a1, b1;
    while (a > 0) {
        a1 += (char)('0' + a % 10);
        a /= 10;
    }
    while (b > 0) {
        b1 += (char)('0' + b % 10);
        b /= 10;
    }
    fr(i, a1.size())
        fr(j, b1.size())
            if (a1[i] == b1[j])
                return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    int ans = 0;
    frab(i, 1, sqrt(n) + 1) {
        if (n % i == 0) {
            if (i < n / i)
                ans += check(n, i) + check(n, n / i);
            if (i == n / i)
                ans += check(n, i);
        }
    }
    cout << ans;

}