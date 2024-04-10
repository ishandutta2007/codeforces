#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 501;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    int cur = 0;
    vector <int> ans;
    frab(i, 1, MOD)
        if (cur < n && a[cur] == i)
            cur++;
        else if (m < i)
            break;
        else {
            ans.pb(i);
            m -= i;
        }
    cout << ans.size() << endl;
    for (auto t: ans)
        cout << t << " ";

}