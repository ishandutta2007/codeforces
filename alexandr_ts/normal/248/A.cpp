#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int a[N];
int fib[N];

int main() {
    int n, c1 = 0, c2 = 0, t1, t2;
    cin >> n;
    fr(i, n) {
        cin >> t1 >> t2;
        c1 += t1;
        c2 += t2;
    }
    cout << min(c1, n - c1) + min(c2, n - c2);
}