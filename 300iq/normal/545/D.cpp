#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    multiset <long long> s;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    long long cur_sum = *s.begin();
    s.erase(s.begin());
    int ans = 1;
    for (int i = 1; i < n; i++) {
        set <long long>::iterator it = s.lower_bound(cur_sum);
        if (it != s.end()) {
            ans++;
            cur_sum += *it;
            s.erase(it);
        } else {
            cur_sum += *s.begin();
            s.erase(s.begin());
        }
    }
    cout << ans << endl;
}