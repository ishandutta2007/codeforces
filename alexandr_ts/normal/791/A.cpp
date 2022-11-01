#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    ll a, b;
    cin >> a >> b;
    for (int i = 0;;i++) {
        a *= 3;
        b *= 2;
        if (a > b) {
            cout << i + 1;
            return 0;
        }
    }
}