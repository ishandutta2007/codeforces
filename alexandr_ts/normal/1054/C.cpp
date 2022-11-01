#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

int l[N], r[N];
int ans[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    fr(i, n)
        scanf("%d", &l[i]);
    fr(i, n)
        scanf("%d", &r[i]);
    int cnt = 0;
    fill(ans, ans + n, -1);
    int curNum = n;
    while (true) {
        vector <int> nums;
        fr(i, n)
            if (l[i] == 0 && r[i] == 0 && ans[i] == -1) {
                nums.pb(i);
                ans[i] = curNum;
            }
        if (!nums.size()) {
            fr(i, n)
                if (l[i] != 0 || r[i] != 0) {
                    cout << "NO";
                    return 0;
                }
            break;
        }

        for (auto x: nums) {
            for (int i = x + 1; i < n; i++)
                if (ans[i] == -1)
                    l[i]--;
            for (int i = 0; i < x; i++)
                if (ans[i] == -1)
                    r[i]--;
        }
        curNum--;
    }
    cout << "YES\n";
    fr(i, n)
        cout << ans[i] << " ";
}