#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> s(n),d(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> d[i];
    }
    int min_time = 1e9;
    int kek2 = 0;
    for (int i = 0; i < n; i++) {
        int kek = 0;
        if (t >= s[i])
            kek = (t - s[i] + d[i] - 1) / d[i];
        if (min_time > kek * d[i] + s[i]) {
            min_time = kek * d[i] + s[i];
            kek2 = i;
        }
    }
    cout << kek2 + 1 << endl;

    




    return 0;
}