#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 2 * 1e6;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

struct pt {
    int x, y;
    bool operator < (const pt a) const {
        return x < a.x || x == a.x && y < a.y;
    }
} a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int last = -INF, n;
    cin >> n;
    fr(i, n) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n);
    fr(i, n)
        if (last > a[i].y)
            last = a[i].x;
        else
            last = a[i].y;
    cout << last;


}