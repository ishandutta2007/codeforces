#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 5e6 + 1;
const int MAX2 = 1e4;

int a[N], b[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    fr(i, n) {
        cin >> a[i];
        b[i % k] += a[i];
    }
    fr(i, k)
        if (b[i] == *min_element(b, b + k)) {
            cout << i + 1;
            return 0;
        }

}