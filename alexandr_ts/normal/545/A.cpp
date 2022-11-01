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
    int n;
    vector <int> ans;
    cin >> n;
    fr(i, n)
        fr(j, n)
            cin >> a[i][j];
    fr(i, n) {
        bool er = false;
        fr(j, n)
            if (a[i][j] == 1 || a[i][j] == 3)
                er = true;
        if (!er)
            ans.pb(i);
    }
    cout << ans.size() << endl;
    fr(i, ans.size())
        cout << ans[i] + 1 << " ";


}