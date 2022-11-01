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
const ld EPS = 1e-9;

int a[N], c[N];
vector <int> b;

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        fill(a, a + n, 0);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        int pos = -1;
        for (int j = n - 1; j >= 0; j--)
            if (a[j] == *max_element(a, a + n))
                pos = j;
        b.pb(pos);
    }
    for (int i = 0; i < b.size(); i++)
        c[b[i]]++;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
        if (c[i] == *max_element(c, c + n))
            ans = i;
    cout << ans + 1 << endl;
}