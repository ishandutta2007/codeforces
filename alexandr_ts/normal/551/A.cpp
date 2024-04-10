#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const int INF = 2 * 1e9 + 1;
const ld EPS = 1e-9;

struct tmp {
    int x, n, p;
};

bool cmp(tmp a, tmp b) {
    return a.x > b.x;
}

bool cmp2(tmp a, tmp b) {
    return a.n < b.n;
}

tmp a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i].x;
        a[i].n = i;
    }
    sort(a, a + n, cmp);
    fr(i, n) {
        if (i && a[i].x == a[i - 1].x)
            a[i].p = a[i - 1].p;
        else
            a[i].p = i;
    }
    sort(a, a + n, cmp2);
    fr(i, n)
        cout << a[i].p + 1 << " ";

}