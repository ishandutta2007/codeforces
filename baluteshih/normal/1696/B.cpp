#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int arr[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0, flag = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            if (arr[i] != 0) {
                if (flag == 0)
                    ++cnt, flag = 1;
            }
            else {
                if (flag == 1)
                    flag = 0;
            }
        }
        cout << min(cnt, 2) << "\n";
    }
}