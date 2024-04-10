#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 301;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

int a[N];
int b[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    frab(i, 1, n) {
        b[i] = max(0, k - a[i] - a[i - 1]);
        a[i] += b[i];
    }
    cout << accumulate(b, b + n, 0) << endl;
    fr(i, n)
        cout << a[i] << " ";
}