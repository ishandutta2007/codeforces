#include<bits/stdc++.h>

using namespace std;

int good[31][100005];
int used[100005];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    vector < int > a;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a.push_back(x);
        for (int j = 0; j <= 30; ++j) {
            if ((x&(1 << j)) > 0) good[j][i] = 1;
        }
    }
    int start = 0;
    for (int j = 30; j >= 0; --j) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) sum += good[j][i];
        if (sum != 1) continue;
        start += (1 << j);
        for (int i = 1; i <= n; ++i) {
            if (good[j][i] == 0 && used[i] == 0) {
                used[i] = 1;
                for (int j = 0; j <= 30; ++j) {
                    if ((a[i - 1]&(1 << j)) > 0) good[j][i] = 0;
                }
            }
        }
    }
    int was = 0;
    for (auto key : a) {
        if ((start|key) == key) was = key;
    }
    cout << was << " ";
    int oks = 0;
    for (auto key : a) {
        if (oks || key != was) cout << key << ' ';
        else {
            oks = 1;
        }
    }
    return 0;
}