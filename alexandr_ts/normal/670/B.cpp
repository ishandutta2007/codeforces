#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ld EPS = 1e-10;
const int INF = 2e9 + 1;

int a[N];

int main() {
    //freopen ("manyangle.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    fr(i, n) {
        if (i + 1 >= k) {
            cout << a[k - 1];
            return 0;
        }
        if (i + 1 < k)
            k -= (i + 1);
    }
}