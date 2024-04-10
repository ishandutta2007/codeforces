#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

void norm(vector<int>& a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> A(n);
    vector<int> yvalues, xvalues;
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first >> A[i].second;
        yvalues.push_back(A[i].second);
        yvalues.push_back(A[i].second + k);
        xvalues.push_back(A[i].first);
        xvalues.push_back(A[i].first + k);
    }

    norm(xvalues);
    norm(yvalues);
    vector<int> count(SZ(yvalues), 0);
    vector<int> last(n + 1, 0);
    vector<int> lastCount(n + 1, 0);
    vector<int64_t> totalCount(n + 1, 0);
    sort(A.begin(), A.end());

    int left = 0, right = 0;
    for (int i = 0; i < SZ(xvalues); ++i) {
        int xcurr = xvalues[i];
        while (right < n && A[right].first <= xvalues[i]) {
            int p = lower_bound(yvalues.begin(), yvalues.end(), A[right].second)
                    - yvalues.begin();
            for (int j = p; j < SZ(yvalues) - 1 &&
                    yvalues[j] - A[right].second < k; ++j) {
                int pcnt = yvalues[j + 1] - yvalues[j];
                int x = count[j];
                totalCount[x] += (int64_t) (xcurr - last[x]) * lastCount[x];
                lastCount[x] -= pcnt;
                last[x] = xcurr;
                count[j]++;
                x = count[j];
                totalCount[x] += (int64_t) (xcurr - last[x]) * lastCount[x];
                lastCount[x] += pcnt;
                last[x] = xcurr;
            }
            right++;
        }
        while (left < right && A[left].first + k <= xvalues[i]) {
            int p = lower_bound(yvalues.begin(), yvalues.end(), A[left].second)
                    - yvalues.begin();
            for (int j = p; j < SZ(yvalues) - 1 &&
                    yvalues[j] - A[left].second < k; ++j) {
                int pcnt = yvalues[j + 1] - yvalues[j];
                int x = count[j];
                totalCount[x] += (int64_t) (xcurr - last[x]) * lastCount[x];
                lastCount[x] -= pcnt;
                last[x] = xcurr;
                count[j]--;
                x = count[j];
                totalCount[x] += (int64_t) (xcurr - last[x]) * lastCount[x];
                lastCount[x] += pcnt;
                last[x] = xcurr;
            }
            left++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << totalCount[i] << ' ';
    }
    cout << '\n';
}