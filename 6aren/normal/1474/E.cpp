#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> q(n);
        for (int i = 0; i < n; i++) q[i] = i;
        
        long long max_time = 0LL;
        vector<pair<int, int>> ops;
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            max_time += (long long) (n - 1 - i) * (n - 1 - i);
            swap(q[i], q[n - 1]);
            ops.push_back({i, n - 1});
            if (j != i && j != n - 1) {
                max_time += (long long) j * j;
                swap(q[0], q[j]);
                ops.push_back({j, 0});
            } 
        }

        cout << max_time << '\n';
        for (int e : q) cout << e + 1 << ' ';
        cout << '\n';
        cout << ops.size() << '\n';
        for (auto it = ops.rbegin(); it != ops.rend(); it++) {
            cout << it->first + 1 << ' ' << it->second + 1 << '\n';
        }
    }

    return 0;
}