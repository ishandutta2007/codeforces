#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const int INF = 2e9 + 1;

int a[N];

int main() {
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    int sum = 0;
    fr(i, n + 1) {
        if (sum >= m) {
            cout << i;
            return 0;
        }
        sum += a[i];
    }
}