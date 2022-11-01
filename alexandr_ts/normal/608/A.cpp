#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const int INF = 2e9 + 1;

struct tmp {
    int st, t;
} a[N];

bool cmp(tmp a, tmp b) {
    return a.st > b.st;
}

int main() {
    int n, s;
    cin >> n >> s;
    fr(i, n)
        cin >> a[i].st >> a[i].t;
    sort(a, a + n, cmp);
    a[n].st = 0;
    a[n].t = -INF;
    int ans = 0;
    fr(i, n + 1) {
        ans += (s - a[i].st);
        s = a[i].st;
        if (ans < a[i].t)
            ans = a[i].t;
    }
    cout << ans;
}