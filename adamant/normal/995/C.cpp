#include <bits/stdc++.h>

#define int int64_t
using namespace std;

typedef int ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype dot(point a, point b) {
    return (conj(a) * b).x();
}
ftype cross(point a, point b) {
    return (conj(a) * b).y();
}

point normal(point x) {
    if(x.y() < 0 || x.y() == 0 && x.x() < 0) {
        x = -x;
    }
    return x;
}

bool le(point a, point b) {
    return cross(a, b) > 0;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x[n], y[n];
    point r[n];
    auto cmp = [](const tuple<point, int, int> &a, const tuple<point, int, int> &b) {
        if(get<0>(a) != get<0>(b)) {
            return le(get<0>(a), get<0>(b));
        } else {
            return get<1>(a) < get<1>(b);
        }
    };
    set<tuple<point, int, int>, decltype(cmp)> lol(cmp);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        r[i] = {x[i], y[i]};
        point t = normal(r[i]);
        int x = normal(r[i]) != r[i];
        lol.insert({t, i, x});
    }
    point cur = 0;
    int ans[n];
    while(!lol.empty()) {
        auto it1 = begin(lol);
        auto it2 = prev(end(lol));
        auto it3 = lol.lower_bound({normal(cur), 0, 0});
        if(it3 == end(lol)) {
            it3--;
        }
        auto it4 = it3;
        if(it4 != begin(lol)) {
            it4--;
        }
        vector<decltype(it1)> its = {it1, it2, it3, it4};
        auto win_it = it1;
        int best = 1e16;
        for(auto it: its) {
            int idx = get<1>(*it);
            ans[idx] = get<2>(*it);
            point nw = get<0>(*it);
            int A = norm(cur + nw);
            int B = norm(cur - nw);
            if(A < best) {
                win_it = it;
                best = A;
            }
            if(B < best) {
                win_it = it;
                best = B;
            }
        }
        auto it = win_it;int idx = get<1>(*it);
            ans[idx] = get<2>(*it);
            point nw = get<0>(*it);
            lol.erase(it);
            int A = norm(cur + nw);
            int B = norm(cur - nw);
            if(A > B) {
                ans[idx] ^= 1;
                cur -= nw;
            } else {
                cur += nw;
            }
    }
    point curr = 0;
    for(int i = 0; i < n; i++) {
        int c = ans[i] ? -1 : 1;
        curr += c * r[i];
        cout << c << ' ';
    }
    return 0;
}