#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const int N = 1e5;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int MAX = 1e6;

struct pt {
    int x,y;
} a[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
//    freopen("a.in", "r", stdin);
    fr(i, 3)
        cin >> a[i].x >> a[i].y;
    int ans = 3;
    fr(i, 50000) {
        random_shuffle(a, a + 3);
        if (a[0].x == a[1].x && a[1].x == a[2].x)
            ans = min(ans, 1);
        if (a[0].y == a[1].y && a[1].y == a[2].y)
            ans = min(ans, 1);
        if (a[0].x == a[1].x && (a[2].y <= min(a[0].y, a[1].y) || a[2].y >= max(a[0].y, a[1].y)))
            ans = min(ans, 2);
        if (a[0].y == a[1].y && (a[2].x <= min(a[0].x, a[1].x) || a[2].x >= max(a[0].x, a[1].x)))
            ans = min(ans, 2);
    }
    fr(i, 3) {
        rotate(a, a + 1, a + 3);
        if (a[0].x == a[1].x && a[1].x == a[2].x)
            ans = min(ans, 1);
        if (a[0].y == a[1].y && a[1].y == a[2].y)
            ans = min(ans, 1);
        if (a[0].x == a[1].x && (a[2].y <= min(a[0].y, a[1].y) || a[2].y >= max(a[0].y, a[1].y)))
            ans = min(ans, 2);
        if (a[0].y == a[1].y && (a[2].x <= min(a[0].x, a[1].x) || a[2].x >= max(a[0].x, a[1].x)))
            ans = min(ans, 2);
    }
    swap(a[0], a[1]);
    fr(i, 3) {
        rotate(a, a + 1, a + 3);
        if (a[0].x == a[1].x && a[1].x == a[2].x)
            ans = min(ans, 1);
        if (a[0].y == a[1].y && a[1].y == a[2].y)
            ans = min(ans, 1);
        if (a[0].x == a[1].x && (a[2].y <= min(a[0].y, a[1].y) || a[2].y >= max(a[0].y, a[1].y)))
            ans = min(ans, 2);
        if (a[0].y == a[1].y && (a[2].x <= min(a[0].x, a[1].x) || a[2].x >= max(a[0].x, a[1].x)))
            ans = min(ans, 2);
    }
    cout << ans;
}