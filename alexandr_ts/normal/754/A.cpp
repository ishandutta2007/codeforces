#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 10;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int pos = -1;
    int sum = 0;
    fr(i, n) {
        cin >> a[i];
        sum += a[i];
        if (sum && pos == -1)
            pos = i;
    }
    if (sum != 0) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << " " << n;
        return 0;
    }
    if (pos != -1 && pos < n - 1) {
        cout << "YES" << endl << 2 << endl;
        cout << "1 " << pos + 1 << endl;
        cout << pos + 2 << " " << n;
        return 0;
    }
    cout << "NO";

}