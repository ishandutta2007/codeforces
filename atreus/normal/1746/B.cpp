#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;

int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int answer = 0;
        vector<int> z;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 0)
                z.push_back(i);
        }
        for (int i = 1; !z.empty() and z.back() >= i and i <= n; i++) {
            if (a[i] == 0)
                continue;
            int idx = z.back();
            a[idx] = 1;
            z.pop_back();
            a[i] = 1;
            answer++;
        }
        cout << answer << '\n';
    }
}