#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        long long total = n * (n - 1) / 2 + n;
        long long trash_sum = n - m;
        long long trash_cnt = 0;
        if (m < (n + 1) / 2) {
            trash_cnt = m + 1;
        } else {
            trash_cnt = (n + 1) / 2 - (m - (n + 1) / 2);
        }
        if (trash_cnt == 0) {
            cout << total << "\n";
            continue;
        }
        long long min_trash = trash_sum / trash_cnt;
        long long o = trash_sum % trash_cnt;
        long long trash = (min_trash * (min_trash - 1) / 2 + min_trash) * (trash_cnt - o) + ((min_trash + 1) * min_trash / 2 + min_trash + 1) * o;
        cout << total - trash << "\n";
    }
	return 0;
}