#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < (ll)n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e16 + 10;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 1003;
const int N = 1e5 + 1;

int a[N][6];
int yes[N];

bool bad(int i, int j, int k) {
    vector <int> b(5), c(5);
    fr(i1, 5)
        b[i1] = a[j][i1] - a[i][i1], c[i1] = a[k][i1] - a[i][i1];
    ll sum = 0;
    fr(i, 5)
        sum += b[i] * c[i];
    return sum > 0;
}

bool used[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        fr(j, 5)
            cin >> a[i][j];

    set <int> s;
    fr(i, n)
        s.insert(i);

    int i1 = 0, i2 = 1, i3 = 2;
    while (i1 < n && i2 < n && i3 < n) {
        used[i1] = used[i2] = used[i3] = true;
        if (bad(i1, i2, i3)) {
            yes[i1] = 1;
            while (used[i1] && i1 < n)
                i1++;
        }
        else if (bad(i2, i1, i3)) {
            yes[i2] = 1;
            while (used[i2] && i2 < n)
                i2++;
        }
        else if (bad(i3, i1, i2)) {
            yes[i3] = 1;
            while (used[i3] && i3 < n)
                i3++;
        }
        else
            assert(false);
    }

    fr(i, n)
        frab(j, i + 1, n) {
            if (i1 < n && i != i1 && j != i1)
                if (bad(i1, i, j))
                    yes[i1] = 1;
            if (i2 < n && i != i2 && j != i2)
                if (bad(i2, i, j))
                    yes[i2] = 1;
            if (i3 < n && i != i3 && j != i3)
                if (bad(i3, i, j))
                    yes[i3] = 1;
        }

    vector <int> ans;
    fr(i, n)
        if (!yes[i])
            ans.pb(i);
    cout << ans.size() << endl;
    for (auto t: ans)
        cout << t + 1 << endl;
}