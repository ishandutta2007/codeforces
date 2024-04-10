#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, x;
    cin >> n >> k;
    deque < int > t;
    set < int > used;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (used.find(x) != used.end()) continue;
        if ((int)t.size() < k) {
            t.push_front(x);
            used.insert(x);
        }
        else {
            used.erase(t.back());
            t.pop_back();
            used.insert(x);
            t.push_front(x);
        }
    }
    cout << t.size() << '\n';
    for (auto key : t) cout << key << " ";
    return 0;
}