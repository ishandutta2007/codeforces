#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 10000*10000;
const ll INF = 2e9 + 10;

vector <int> a;

int digsum(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

bool ok(int x) {
    int x1 = x;
    int sum2 = 0;
    while (x1 > 1) {
        bool fnd = false;
        for (int i = 2; i * i <= x1; i++)
            if (x1 % i == 0) {
                sum2 += digsum(i);
                x1 /= i;
                fnd = true;
                break;
            }
        if (!fnd) {
            sum2 += digsum(x1);
            x1 = 0;
        }
    }
    if (sum2 != digsum(x))
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 2; a.size() < n; i++)
        if (ok(i))
            a.pb(i);
    cout << a[n - 1];
}