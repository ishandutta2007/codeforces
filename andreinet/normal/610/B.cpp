#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> A(2 * n);

    deque<int> poss;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        A[n + i] = A[i];
    }

    int64_t ans = 0;
    for (int i = 0; i < 2 * n; ++i) {
        while (!poss.empty() && poss.front() <= i - n) {
            poss.pop_front();
        }
        while (!poss.empty() && A[i] < A[poss.back()]) {
            poss.pop_back();
        }
        poss.push_back(i);
        if (i >= n) {
            int64_t c = (int64_t) 
                A[poss.front()] * n + (poss.front() - (i - n) - 1);
            ans = max(ans, c);
        }
    }
    cout << ans << '\n';
}