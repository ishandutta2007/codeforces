#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005;

struct Cylinder {
    int h, r, pos;
    int64_t volume() const {
        return (int64_t) h * r * r;
    }
    bool operator<(const Cylinder& o) const {
        return volume() < o.volume();
    }
};

int64_t aib[NMAX];

void update(int pos, int64_t value) {
    for (; pos < NMAX - 4; pos += pos & -pos) {
        aib[pos] = max(aib[pos], value);
    }
}

int64_t query(int pos) {
    int64_t ret = 0;
    for (; pos > 0; pos -= pos & -pos) {
        ret = max(ret, aib[pos]);
    }
    return ret;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<Cylinder> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].r >> A[i].h;
        A[i].pos = i + 1;
    }
    sort(A.begin(), A.end());

    vector<int64_t> B(n);
    for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && A[i].volume() == A[j].volume(); ++j);

        for (int k = i; k < j; ++k) {
            B[k] = query(A[k].pos - 1) + A[k].volume();
        }
        for (int k = i; k < j; ++k) {
            update(A[k].pos, B[k]);
        }
    }

    int64_t ans = *max_element(B.begin(), B.end());
    cout << setprecision(17) << fixed;
    cout << ans * acos(-1) << '\n';
}