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

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        int l, r;
        cin >> l >> r;
        a[i] = r - l;
    }
    int sum = accumulate(a, a + n, 0);
    int curs = abs(sum), pos = -1;
    fr(i, n)
        if (abs(sum - 2 * a[i]) > curs)
            curs = abs(sum - 2 * a[i]), pos = i;
    cout << pos + 1;
}