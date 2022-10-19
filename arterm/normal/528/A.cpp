#include <bits/stdc++.h>

using namespace std;

struct Seg {
    set<int> a;
    multiset<int> b;

    Seg(int n) {
        a.insert(0);
        a.insert(n);
        b.insert(n);
    }

    void cut(int x) {
        auto r = a.lower_bound(x);
        auto l = r;
        --l;

        int R = *r;
        int L = *l;

        a.insert(x);
        b.erase(b.find(R - L));
        b.insert(x - L);
        b.insert(R - x);
    }

    int getMax() {
        return *b.rbegin();
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int w, h, n;
    cin >> w >> h >> n;

    Seg V(w), H(h);
    for (int i = 0; i < n; ++i) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'V')
            V.cut(x);
        else
            H.cut(x);
        cout << (1ll * V.getMax() * H.getMax()) << "\n";
    }
    return 0;
}