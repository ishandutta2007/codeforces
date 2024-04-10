#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const int M = 2e3 + 10;
const int POW = 20;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

const int N = 1e6 + 10;

int a[N], b[N];
int c[N], d[N];

bool check(int n) {
    int c1 = 0, c2 = 0;
    fr(i, n) {
        if (c[i] != a[i]) c1++;
        if (c[i] != b[i]) c2++;
    }
    return c1 == 1 && c2 == 1;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n)
        cin >> b[i];

    vector <int> v1, v2;
    int l1 = -1, l2 = -1;
    fr(i, n)
        frab(j, i + 1, n) {
            if (a[i] == a[j])
                v1.pb(i), v1.pb(j);
            if (b[i] == b[j])
                v2.pb(i), v2.pb(j);
        }
    assert(v1.size() == 2);
    assert(v2.size() == 2);
    frab(i, 1, 1 + n) {
        bool fnd = false;
        fr(i1, n)
            if (a[i1] == i)
                fnd = true;
        if (!fnd) l1 = i;
    }


    //cout << l1 << " " << v1[0] << endl;

    fr(i1, 2)
        fr(i2, 2) {
            fr(i, n) c[i] = a[i], d[i] = b[i];
            c[v1[i1]] = l1;
            if (check(n)) {
                fr(i, n)
                    cout << c[i] << " ";
                return 0;
            }
            //d[v2[i]] = l2;
        }
    assert(false);
}