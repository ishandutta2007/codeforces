#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 3e5 + 10;
const ll INF = 2e9;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

struct tmp {
    int x, y, num;
} a[N];

bool cmp(tmp a, tmp b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n;
    int mxy = -INF;
    cin >> n;
    fr(i, n) {
        cin >> a[i].x >> a[i].y;
        mxy = max(mxy, a[i].y);
        a[i].num = i + 1;
    }
    sort(a, a + n, cmp);
    fr(i, n)
        if (a[i].x == a[0].x) {
            if (a[i].y == mxy) {
                cout << a[i].num;
                return 0;
            }
        }
        else break;
    cout << -1;
}