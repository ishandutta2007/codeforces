#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3;
const int INF = 2 * 1e9 + 1;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int q1 = max(3 * a / 10, a - a / 250 * c);
    int q2 = max(3 * b / 10, b - b / 250 * d);
    if (q1 > q2)
        cout << "Misha";
    if (q1 == q2)
        cout << "Tie";
    if (q1 < q2)
        cout << "Vasya";
}