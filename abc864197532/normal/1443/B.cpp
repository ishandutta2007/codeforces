#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, x = 864197532, N = 587, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        deque <int> dq(s.begin(), s.end());
        while (dq.size() && dq.front() == '0') dq.pop_front();
        while (dq.size() && dq.back() == '0') dq.pop_back();
        if (dq.empty()) {
            cout << 0 << endl;
            continue;
        }
        vector <int> aa;
        int cnt = 0;
        for (int i = 0; i < dq.size(); ++i) {
            if (dq[i] == '0') {
                cnt++;
            } else {
                if (cnt > 0) aa.push_back(cnt);
                cnt = 0;
            }
        }
        int cur_ans = (aa.size() + 1) * a;
        for (int i : aa) {
            if (i * b < a) {
                cur_ans -= a - i * b;
            }
        }
        cout << cur_ans << endl;
    }
}