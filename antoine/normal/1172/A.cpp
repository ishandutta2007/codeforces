#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;
int a[MxN + 9]; // her hands
int b[MxN + 9]; // stack

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    // n = 1 !

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];


    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i])
            ans = max(ans, n - a[i] + 1);
        if (b[i]) {
            if (i >= b[i])
                ans = max(ans, i - b[i]);
            else
                ans = max(ans, i + (n - b[i] + 1));
        }
    }


    vector<int> diffs;

    for (int i = 1; i <= n; ++i)
        if (b[i] && i >= b[i])
            diffs.push_back(i - b[i]);


    sort(diffs.begin(), diffs.end());
    for (int d : diffs)
        if (d < ans)
            ans = max(ans, d + n + 1);

    cout << ans;
    return 0;
}