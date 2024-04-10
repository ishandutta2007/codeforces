#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 1e3 + 2;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

int c[N], d[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    int cur = 0;
    vector <int> v1, v2;
    for (int i = 0; i < n; i++)
        cin >> c[i] >> d[i];
    for (int i = n - 1; i >= 0; i--) {
        cur -= c[i];
        if (d[i] == 1)
            v1.pb(cur);
        else
            v2.pb(cur);
    }
    if (v2.size() == 0) {
        cout << "Infinity";
        return 0;
    }
    if (v1.size() == 0) {
        cout << 1899 - *max_element(v2.begin(), v2.end());
        return 0;
    }
    if (*max_element(v2.begin(), v2.end()) >= *min_element(v1.begin(), v1.end())) {
        cout << "Impossible";
        return 0;
    }
    cout << 1899 - *max_element(v2.begin(), v2.end());
}