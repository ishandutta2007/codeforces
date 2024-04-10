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

string a[N];

bool good(string x) {
    if (x[0] != '1')
        return false;
    frab(i, 1, x.size())
        if (x[i] != '0')
            return false;
    return true;
}

int main() {
    ld start = clock() / CLOCKS_PER_SEC;
    srand(time(NULL));
    //freopen("spacepin.in", "r", stdin);
    //freopen("spacepin.out", "w", stdout);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i];
        if (a[i] == "0") {
            cout << 0;
            return 0;
        }
    }
    string ans;
    fr(i, n) {
        if (!good(a[i]))
            ans += a[i];
    }
    fr(i, n) {
        if (good(a[i]))
            if (ans.size())
                ans += a[i].substr(1, (int)a[i].size() - 1);
            else
                ans += a[i];
    }
    cout << ans;


}