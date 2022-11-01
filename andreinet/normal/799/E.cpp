#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    if (m < k) {
        cout << "-1\n";
        return 0;
    }

    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }
    vector<bool> byA(n, false), byB(n, false);
    {
        int k;
        cin >> k;
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            x--;
            byA[x] = true;
        }
    }
    {
        int k;
        cin >> k;
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            x--;
            byB[x] = true;
        }
    }
    vector<int> a, b, both, neither;
    for (int i = 0; i < n; ++i) {
        if (byA[i] && byB[i]) {
            both.push_back(costs[i]);
        } else if (byA[i]) {
            a.push_back(costs[i]);
        } else if (byB[i]) {
            b.push_back(costs[i]);
        } else {
            neither.push_back(costs[i]);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(both.begin(), both.end());
    sort(neither.begin(), neither.end());
    multiset<int> setR, setOther;
    int r = 0;
    int64_t sum = 0;
    for (int i = 0; i < SZ(neither); ++i) {
        setR.insert(neither[i]);
        sum += neither[i];
    }
    auto balance = [&]() -> void {
        while (SZ(setR) > r) {
            auto it = setR.end();
            --it;
            sum -= *it;
            setOther.insert(*it);
            setR.erase(it);
        }
        while (SZ(setR) < r && !setOther.empty()) {
            auto it = setOther.begin();
            sum += *it;
            setR.insert(*it);
            setOther.erase(it);
        }
    };
    auto insert = [&](int value) -> void {
        if (setOther.empty()) {
            if (setR.empty()) {
                setR.insert(value);
                sum += value;
            } else {
                auto it = setR.end();
                --it;
                if (value < *it) {
                    setR.insert(value);
                    sum += value;
                } else {
                    setOther.insert(value);
                }
            }
        } else {
            if (value < *setOther.begin()) {
                setR.insert(value);
                sum += value;
            } else {
                setOther.insert(value);
            }
        }
        balance();
    };
    auto erase = [&](int value) -> void {
        auto it = setR.find(value);
        if (it != setR.end()) {
            setR.erase(it);
            sum -= value;
        } else {
            setOther.erase(setOther.find(value));
        }
        balance();
    };
    for (int i = 0; i < SZ(both); ++i) {
        insert(both[i]);
    }
    vector<int64_t> suma(SZ(a)), sumb(SZ(b));
    if (SZ(a) > 0) {
        suma[0] = a[0];
        for (int i = 1; i < SZ(a); ++i) {
            suma[i] = suma[i - 1] + a[i];
        }
    }
    if (SZ(b) > 0) {
        sumb[0] = b[0];
        for (int i = 1; i < SZ(b); ++i) {
            sumb[i] = sumb[i - 1] + b[i];
        }
    }
    for (int i = k; i < SZ(a); ++i) {
        insert(a[i]);
    }
    for (int i = k; i < SZ(b); ++i) {
        insert(b[i]);
    }
    int64_t sumBoth = 0;
    int64_t ans = 1LL << 62;
    for (int i = 0; i <= SZ(both) && i <= k; ++i) {
        int x = k - i;
        if (x - 1 < SZ(a) && x - 1 < SZ(b) && m - (i + 2 * x) >= 0) {
            r = m - (i + 2 * x);
            balance();
            ans = min(ans, sumBoth + (x - 1 >= 0 ? suma[x - 1] + sumb[x - 1]: 0)
                    + sum);
        }
        if (x - 1 >= 0 && x - 1 < SZ(a)) {
            insert(a[x - 1]);
        }
        if (x - 1 >= 0 && x - 1 < SZ(b)) {
            insert(b[x - 1]);
        }
        if (i < SZ(both)) {
            erase(both[i]);
            sumBoth += both[i];
        }
    }
    if (ans == (1LL << 62)) {
        ans = -1;
    }
    cout << ans << '\n';
}