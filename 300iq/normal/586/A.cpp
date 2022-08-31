#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, x;
    deque <int> q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push_back(x);
    }
    while (q.size() > 0 && q.front() == 0) {
        q.pop_front();
    }
    while (q.size() > 0 && q.back() == 0) {
        q.pop_back();
    }
    int ans = 0;
    int cnt = 0;
    while (q.size() > 0) {
        if (q.front() == 1) {
            if (cnt < 2) {
                ans += cnt;
            }
            cnt = 0;
            ans++;
        } else {
            cnt++;
        }
        q.pop_front();
    }
    cout << ans << endl;
}