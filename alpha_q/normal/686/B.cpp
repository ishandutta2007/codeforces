#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, a[N], b[N];

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];

    sort (b + 1, b + n + 1);

    for (int i = 1; i <= n; ++i) {
        int x = b[i], j;
        for (j = i; j <= n; ++j) if (a[j] == x) break;
        while (a[i] != x) {
            cout << j - 1 << " " << j << endl;
            swap(a[j], a[j - 1]);
            j--;
        }
    }

    cout.flush();
    return 0;
}