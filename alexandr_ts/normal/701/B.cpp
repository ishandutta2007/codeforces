#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

ll cnt(ll x, bool ex) {
    if (!ex && x == 0)
        return 0;
    frab(i, 1, sqrt(2 * x) * 2 + 100)
        if (i * (i - 1) == 2 * x)
            return i;
    return -1;
}

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    set <int> a, b;
    int n, m;
    cin >> n >> m;
    fr(i, m) {
        int x, y;
        cin >> x >> y;
        a.insert(x);
        b.insert(y);
        cout << ((ll)n - (ll)a.size()) * ((ll)n - (ll)b.size()) << " ";
    }
}