#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 10000*10000;
const ll INF = 2e9 + 10;
const int MAX = 1010;

int a[N], d[2 * MAX + 10];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i1, m) {
        int k;
        cin >> k;
        set <int> s;
        fr(j, k) {
            cin >> a[j];
            s.insert(a[j]);
        }
        bool fnd = false;
        fr(j, k)
            if (s.count(-a[j]))
                fnd = true;
        if (!fnd) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";


}