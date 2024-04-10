#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define read(a) scanf("%d", &a)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, t;
    cin >> n >> t;
    fr(i, n)
        cin >> a[i];

    int ans = 0;
    int tm = 0, cur = 0, curl = 0;
    while (tm  + a[cur] <= t && cur < n) {
        tm += a[cur];
        cur++;
        ans = max(ans, cur);
    }
    frab(i, cur, n) {
        tm -= a[curl++];
        while (tm + a[cur] <= t && cur < n) {
            tm += a[cur];
            cur++;
            ans = max(ans, cur - curl);
        }
    }
    cout << ans;
}