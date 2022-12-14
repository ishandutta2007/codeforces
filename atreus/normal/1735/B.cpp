#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;

int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int mnm = *min_element(a + 1, a + n + 1);
        int k = 2 * mnm - 1;
        long long answer = 0;
        for (int i = 1; i <= n; i++)
            answer += (a[i] + k - 1) / k - 1;
        cout << answer << '\n';
    }
}