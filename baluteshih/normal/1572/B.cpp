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

int arr[200005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, sum = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i], sum += arr[i];
        if (sum & 1) {
            cout << "NO\n";
            continue;
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (arr[i] == 0)
                break;
            else
                ++cnt;
        vector<int> ans;
        while (cnt + 2 <= n && (cnt & 1) == 1) {
            if (arr[cnt + 2] == 1) {
                ans.pb(cnt);
                arr[cnt] = arr[cnt + 2] = 0;
                --cnt;
                break;
            }
            else {
                ans.pb(cnt);
                arr[cnt + 1] = arr[cnt + 2] = 1;
                cnt += 2;
                while (cnt + 1 <= n && arr[cnt + 1] == 1)
                    ++cnt;
            }
        }
        if (cnt == n) {
            cout << "NO\n";
            continue;
        }
        for (int i = cnt - 1; i >= 1; i -= 2) {
            arr[i] = arr[i + 1] = 0;
            ans.pb(i);
        }
        for (int i = cnt + 2; i + 2 <= n; ++i) {
            if (arr[i] == 0)
                continue;
            if (arr[i + 1] == 0) {
                if (arr[i + 2] == 0) {
                    arr[i] = 0;
                    arr[i + 2] = 1;
                    ans.pb(i), ans.pb(i - 1), ++i;
                }
                else {
                    arr[i] = arr[i + 2] = 0;
                    ans.pb(i), i += 2; 
                }
            } 
            else {
                arr[i] = arr[i + 1] = 0;
                ans.pb(i - 1), ++i;
            }
        }
        assert((arr[n - 1] ^ arr[n]) == 0);
        if (arr[n - 1] == 1)
            ans.pb(n - 2);
        cout << "YES\n";
        cout << SZ(ans) << "\n";
        for (int i = 0; i < SZ(ans); ++i)
            cout << ans[i] << " \n"[i + 1 == SZ(ans)];
    }
}