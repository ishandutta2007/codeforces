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
const ld EPS = 1e-9;

ll a[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, t;
    cin >> n;
    multiset <int> s1, s2;
    fr(i, n) {
        cin >> t;
        s1.insert(t);
    }
    fr(i, n - 1) {
        cin >> t;
        s2.insert(t);
        s1.erase(s1.find(t));
    }
    cout << *(s1.begin()) << endl;
    fr(i, n - 2) {
        cin >> t;
        s2.erase(s2.find(t));
    }
    cout << *(s2.begin());


}