#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e9 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

bool a[N], b[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int t, q;
    cin >> q;
    fr(i, q) {
        cin >> t;
        a[t] = true;
    }
    cin >> q;
    fr(i, q) {
        cin >> t;
        b[t] = true;
    }
    fr(i, 1000000) {
        int t1 = i % n;
        int t2 = i % m;
        a[t1] = a[t1] | b[t2];
        b[t2] = a[t1] | b[t2];
        if (i % 10000 == 0)
            if (accumulate(a, a + n, 0) + accumulate(b, b + m, 0) == n + m) {
                cout << "Yes";
                return 0;
            }
    }
    cout << "No";

}