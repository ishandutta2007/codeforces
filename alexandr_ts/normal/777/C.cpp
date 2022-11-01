#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const ll INF = 2e12 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

vector <int> a[N], b[N];
int c[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        a[i].resize(m), b[i].resize(m);
    fr(i, n)
        fr(j, m)
            cin >> a[i][j];

    fr(i, n)
        fr(j, m)
            if (i && a[i][j] >= a[i - 1][j])
                b[i][j] = b[i - 1][j];
            else
                b[i][j] = i;
    fr(i, n)
        c[i] = *min_element(b[i].begin(), b[i].end());
    int k;
    cin >> k;
    fr(i, k) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (c[r] <= l)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}