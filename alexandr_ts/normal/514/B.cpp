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

const ll N = 1e6 + 10;
const ld EPS = 1e-13;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

struct pt {
    int x, y;
    bool operator < (const pt a) const {
        return x < a.x || x == a.x && y < a.y;
    }
};

int main() {
    //ld st1 = clock();
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    set <pt> m;
    pt a;
    cin >> a.x >> a.y;
    fr(i, n) {
        pt tmp;
        cin >> tmp.x >> tmp.y;
        tmp.x -= a.x;
        tmp.y -= a.y;
        if (tmp.x < 0) {
            tmp.x *= -1;
            tmp.y *= -1;
        }
        int x = __gcd(tmp.x, tmp.y);
        tmp.x /= x;
        tmp.y /= x;
        m.insert(tmp);
    }
    cout << m.size();

}