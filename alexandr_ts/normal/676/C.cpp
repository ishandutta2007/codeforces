#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

int a[N], b[N], c[N], d[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 1;
    int cura = 0, curb = 0, cur = 0;

    fr(i, n) {
        if (s[i] == 'a') cura++;
        else curb++;
        while (cur <= i && min(cura, curb) > k) {
            if (s[cur] == 'a')
                cura--;
            else
                curb--;
            cur++;
        }
        ans = max(ans, i - cur + 1);
    }
    cout << ans;
}