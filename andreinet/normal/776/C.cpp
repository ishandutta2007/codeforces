#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int64_t INF = 1LL << 62;

template<class T>
int getPos(const vector<T>& a, const T& e) {
    return lower_bound(a.begin(), a.end(), e) - a.begin();
}

template<class T>
class FenwickTree {
public:
    FenwickTree(int n):
        tree(n + 1, 0) {}
    void update(int pos, int val) {
        for (++pos; pos < SZ(tree); pos += pos & -pos) {
            tree[pos] += val;
        }
    }
    T query(int pos) const {
        T ret = 0;
        for (++pos; pos > 0; pos -= pos & -pos) {
            ret += tree[pos];
        }
        return ret;
    }
private:
    vector<T> tree;
};

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

    vector<int64_t> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    
    map<int64_t, int> cnt;
    cnt[sum[0]]++;
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (abs(k) <= 1) {
            vector<int> v = {1};
            if (k == -1) v.push_back(-1);
            for (int64_t pw: v) {
                int64_t s = sum[i] - pw;
                auto it = cnt.find(s);
                if (it != cnt.end()) {
                    ans += it->second;
                }
                if (abs(pw) >= abs(INF / k)) {
                    break;
                }
            }
        } else {
            for (int64_t pw = 1; ; pw *= k) {
                int64_t s = sum[i] - pw;
                auto it = cnt.find(s);
                if (it != cnt.end()) {
                    ans += it->second;
                }
                if (abs(pw) >= abs(INF / k)) {
                    break;
                }
            }
        }
        cnt[sum[i]]++;
    }
    cout << ans << '\n';
}