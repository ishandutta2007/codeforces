#include <bits/stdc++.h>
#define pb push_back
#define fr(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = 1e4 + 10;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 2e3 + 10;
const ld MAX = 1e18;
const int N = 1e5 + 10;

vector <int> a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;

    set <vector <int> > s;

    for (int i = 0; i < n; i++) {
        a[i].resize(k);
        for (int j = 0; j < k; j++)
            scanf("%d", &a[i][j]);
        s.insert(a[i]);
    }

    vector <int> e0;
    fr(i, k)
        e0.pb(0);

    for (auto t: s) {
        if (t == e0) {
            cout << "YES";
            return 0;
        }
        for (auto t2: s)
        if (t2 != t) {
            vector <int> sum(k);
            fr(j, k)
                sum[j] = t2[j] & t[j];
            if (sum == e0) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}