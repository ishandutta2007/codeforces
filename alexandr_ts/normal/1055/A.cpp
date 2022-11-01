#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int MAX = 1e5 + 1;
const int N = 2e6 + 10;

int a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    k--;
    fr(i, n)
        cin >> a[i];
    fr(i, n)
        cin >> b[i];
    if (!a[0]) {
        cout << "NO";
        return 0;
    }
    if (a[k]) {
        cout << "YES";
        return 0;
    }
    for (int i = k; i < n; i++) {
        if (a[i] && b[k] && b[i]) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}