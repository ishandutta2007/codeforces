#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 5;
const int M = 1025;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-10;

int a[N], b[N], c[N];

int main() {
    //freopen("a.in", "r", stdin);

    int n, k, x;
    cin >> n >> k >> x;
    fr(i, n) {
        cin >> a[i];
        b[a[i]]++;
    }
    sort(a, a + n);

    if (k == 0) {
        cout << a[n - 1] << " " << a[0];
        return 0;
    }

    fr(i, M) {
        while (b[i] > 7)
            b[i] -= 4;
    }


    fr(i1, k) {
        int n1 = 0;
        fr(i, M)
            fr(j, b[i])
                c[n1++] = i;
        for (int i = 0; i < n1; i += 2)
            b[c[i]]--, b[c[i] ^ x]++;
    }
    int n1 = 0;
    fr(i, M)
        fr(j, b[i])
            c[n1++] = i;

    cout << *max_element(c, c + n1) << " ";
    cout << *min_element(c, c + n1);
}