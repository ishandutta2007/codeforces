#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXC = 2500000;
int arr[200005], cnt[MAXC * 2 + 5], ban[200005];
pii pr[MAXC * 2 + 10];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, a = -1, b = -1;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i], ++cnt[arr[i]];
    for (int i = 1; i <= MAXC; ++i) {
        if (cnt[i] > 3) {
            int x = 0, y = 0, z = 0, w = 0;
            for (int j = 1; j <= n; ++j)
                if (arr[j] == i) {
                    if (x == 0)
                        x = j;
                    else if (y == 0)
                        y = j;
                    else if (z == 0)
                        z = j;
                    else if (w == 0)
                        w = j;
                }
            cout << "YES\n";
            cout << x << " " << y << " " << z << " " << w << "\n";
            return 0;
        }
        if (cnt[i] > 1) {
            if (a == -1)
                a = i;
            else if (b == -1) {
                b = i;
                break;
            }
        }
    }
    if (b != -1) {
        int x = 0, y = 0, z = 0, w = 0;
        for (int i = 1; i <= n; ++i)
            if (arr[i] == a) {
                if (x == 0)
                    x = i;
                else if (z == 0)
                    z = i;
            }
            else if (arr[i] == b) {
                if (y == 0)
                    y = i;
                else if (w == 0)
                    w = i;
            }
        cout << "YES\n";
        cout << x << " " << y << " " << z << " " << w << "\n";
        return 0;
    }
    if (a != -1) {
        for (int i = 1; i * 2 < a + a; ++i)
            if (cnt[i] > 0 && cnt[a + a - i] > 0) {
                b = i;
                break;
            }
        if (b != -1) {
            int x = 0, y = 0, z = 0, w = 0;
            for (int i = 1; i <= n; ++i)
                if (arr[i] == a) {
                    if (x == 0)
                        x = i;
                    else if (y == 0)
                        y = i;
                }
                else if (arr[i] == b) {
                    if (z == 0)
                        z = i;
                }
                else if (arr[i] == a + a - b) {
                    if (w == 0)
                        w = i;
                }
            cout << "YES\n";
            cout << x << " " << y << " " << z << " " << w << "\n";
            return 0;
        }
        int flag = 0;
        for (int i = 1; i <= n; ++i)
            if (arr[i] == a) {
                if (flag)
                    ban[i] = 1;
                else
                    flag = 1;
            }
    }
    for (int i = 1; i <= n; ++i) {
        if (ban[i]) continue;
        for (int j = i + 1; j <= n; ++j) {
            if (ban[j]) continue;
            if (pr[arr[i] + arr[j]].X != 0) {
                cout << "YES\n";
                cout << i << " " << j << " " << pr[arr[i] + arr[j]].X << " " << pr[arr[i] + arr[j]].Y << "\n";
                return 0;
            }
            else
                pr[arr[i] + arr[j]] = pii(i, j);
        }
    }
    cout << "NO\n";
}