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

int arr[1005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        cout << n / 2 * 6 << "\n";
        for (int i = 1; i <= n; i += 2) {
            cout << "2 " << i << " " << i + 1 << "\n";
            cout << "1 " << i << " " << i + 1 << "\n";
            cout << "2 " << i << " " << i + 1 << "\n";
            cout << "1 " << i << " " << i + 1 << "\n";
            cout << "2 " << i << " " << i + 1 << "\n";
            cout << "1 " << i << " " << i + 1 << "\n";
        }
    }
}