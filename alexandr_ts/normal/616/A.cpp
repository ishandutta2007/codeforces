#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int INF = 2e9;
const ld EPS = 1e-16;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ld start = clock() / CLOCKS_PER_SEC;
    srand(time(NULL));
    //freopen("spacepin.in", "r", stdin);
    //freopen("spacepin.out", "w", stdout);
    string a, b;
    cin >> a >> b;
    int i = 0;
    while (a[i] == '0') i++;
    int j = 0;
    while (b[j] == '0') j++;
    a = a.substr(i, (int)a.size() - i);
    b = b.substr(j, (int)b.size() - j);
    if (a == b) {
        cout << '=';
        return 0;
    }
    if (a.size() > b.size()) {
        cout << '>';
        return 0;
    }
    if (a.size() < b.size()) {
        cout << '<';
        return 0;
    }
    fr(i, a.size())
        if (a[i] < b[i]) {
            cout << '<';
            return 0;
        }
        else if (a[i] > b[i]) {
            cout << '>';
            return 0;
        }
}