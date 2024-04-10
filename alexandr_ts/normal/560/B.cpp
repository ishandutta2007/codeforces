#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e3 + 10;
const ld EPS = 1e-13;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

struct pt {
    int x, y;
};

pt a[3];

int main() {
    //ld st1 = clock();
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    fr(i, 3)
        cin >> a[i].x >> a[i].y;
    fr(i, 1000) {
        int t = rand() % 2;
        if (t % 2)
            swap(a[1].x, a[1].y);
        t = rand() % 2;
        if (t % 2)
            swap(a[2].x, a[2].y);
        if (a[1].x + a[2].x <= a[0].x && max(a[1].y, a[2].y) <= a[0].y ||
            a[1].y + a[2].y <= a[0].y && max(a[1].x, a[2].x) <= a[0].x) {
            cout << "YES";
            return 0;
        }

    }
    cout << "NO";
}