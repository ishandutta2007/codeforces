#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int a[555555];
int el[555555];
int er[555555];
int last[555555];

struct query {
    int l, r, id;

    bool operator< (const query o) const {
        return l < o.l;
    }
};

query qs[555555];
int ans[555555];

int f[555555];

int get(int r) {
    int res = f[r];
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res = min(res, f[r]);
    }
    return res;
}

void upd(int i, int x) {
    for (; i < 555555; i |= (i + 1)) {
        f[i] = min(f[i], x);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    unordered_map<int, int> nums;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (nums.find(a[i]) == nums.end()) {
            int t = nums.size();
            nums[a[i]] = t;
            a[i] = t;
        } else {
            a[i] = nums[a[i]];
        }
    }

    memset(last, -1, sizeof(last));

    for (int i = 0; i < n; i++) {
        int c = a[i];
        el[i] = last[c];
        last[c] = i;
    }

    memset(last, -1, sizeof(last));
    for (int i = n - 1; i >= 0; i--) {
        int c = a[i];
        er[i] = last[c];
        last[c] = i;
    }

    for (int i = 0; i < m; i++) {
        scid(l, r);
        --l; --r;
        qs[i] = {l, r, i};
    }

    sort(qs, qs + m);
    for (int i = 0; i < n; i++) {
        f[i] = 1e9;
    }

    int ll = n;

    for (int i = m - 1; i >= 0; i--) {
        auto& q = qs[i];
        while (ll > q.l) {
            --ll;
            if (er[ll] != -1) {
                upd(er[ll], er[ll] - ll);
            }
        }
        ans[q.id] = get(q.r);
    }

    for (int i = 0; i < m; i++) {
        cout << (ans[i] == 1e9 ? -1 : ans[i]) << "\n";
    }



    return 0;
}