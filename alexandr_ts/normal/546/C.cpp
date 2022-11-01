#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll N = 1e6;
const ll M = 311;
const ld EPS = 1e-8;
const ll INF = 2 * 1e15 + 1;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n, k1, k2;
    cin >> n;
    cin >> k1;
    queue <int> q1, q2;
    int steps = 0;
    fr(i, k1) {
        int t;
        cin >> t;
        q1.push(t);
    }
    cin >> k2;
    fr(i, k2) {
        int t;
        cin >> t;
        q2.push(t);
    }
    while (q1.size() && q2.size()) {
        int t1 = q1.front();
        int t2 = q2.front();
        q1.pop(), q2.pop();
        if (t1 > t2) {
            q1.push(t2);
            q1.push(t1);
        }
        else {
            q2.push(t1);
            q2.push(t2);
        }
        steps++;
        if (steps > 1e7) {
            cout << -1;
            return 0;
        }
    }
    cout << steps << " ";
    if (q1.size())
        cout << 1;
    else
        cout << 2;
}