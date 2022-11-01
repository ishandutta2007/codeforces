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

const ll N = 1e6 + 10;
const ld EPS = 1e-13;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

int f(char a) {
    int x = a - '0';
    if (x == 0) return 2;
    if (x == 1) return 7;
    if (x == 2) return 2;
    if (x == 3) return 3;
    if (x == 4) return 3;
    if (x == 5) return 4;
    if (x == 6) return 2;
    if (x == 7) return 5;
    if (x == 8) return 1;
    if (x == 9) return 2;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    char a, b;
    cin >> a >> b;
    cout << f(a) * f(b);
}