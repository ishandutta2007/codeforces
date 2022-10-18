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
        int n, one = 0, diff = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        sort(arr + 1, arr + n + 1);
        for (int i = 1; i <= n; ++i)
            if (arr[i] == 1)
                one = 1;
        for (int i = 1; i < n; ++i)
            if (arr[i] + 1 == arr[i + 1])
                diff = 1;
        if (!one)
            cout << "YES\n";
        else if (!diff)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}