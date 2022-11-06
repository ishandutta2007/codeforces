#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int a[333333];
int b[333333];
int n;
llong sa[333333];
llong sia[333333];
llong sb[333333];
llong sib[333333];

void init() {
    for (int i = 0; i < n; i++) {
        sa[i] = a[i];
        sia[i] = 1LL * a[i] * i;
        if (i) {
            sa[i] += sa[i - 1];
            sia[i] += sia[i - 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        sb[i] = b[i];
        sib[i] = 1LL * b[i] * (n - 1 - i);
        if (i + 1 < n) {
            sb[i] += sb[i + 1];
            sib[i] += sib[i + 1];
        }
    }
}

llong geta(int t, int i) {
    int d = t - i;
    return d * (sa[n - 1] - (i ? sa[i - 1] : 0)) + (sia[n - 1] - (i ? sia[i - 1] : 0));
}

llong getb(int t, int i) {
    int d = t;
    return d * sb[i] + sib[i];
}

llong get(int t, int i) {
    llong ra = geta(t, i);
    llong rb = getb(t + n - i, i);
    return ra + rb;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (n == 1) {
        cout << b[0];
        return 0;
    }

    init();

    llong ans = get(0, 0);
    llong ca = 0;
    llong ct = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        ca += ct++ * a[i] + ct++ * b[i] + ct++ * b[i + 1] + ct++ * a[i + 1];
        llong cn = (i + 2 < n ? get(ct, i + 2) : 0);
        ans = max(ans, ca + cn);
    }

    for (int i = 0; i < n; i++) {
        swap(a[i], b[i]);
    }
    b[0] = 0;
    init();
    ct = 2;
    ca = a[0];
    ans = max(ans, ca + get(2, 1));
    for (int i = 1; i + 1 < n; i += 2) {
        ca += ct++ * a[i] + ct++ * b[i] + ct++ * b[i + 1] + ct++ * a[i + 1];
        llong cn = (i + 2 < n ? get(ct, i + 2) : 0);
        ans = max(ans, ca + cn);
    }

    cout << ans;


    return 0;
}//dtnnlw