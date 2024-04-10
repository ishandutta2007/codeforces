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
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

struct pt {
    int x, y;
    
    bool operator==(const pt& r) const {
        return x == r.x && y == r.y;
    }
    
    bool operator<(const pt& r) const {
        return x == r.x ? y < r.y : x < r.x;
    }
    
    pt operator-(pt r) const {
        return pt{x - r.x, y - r.y};
    }
    pt operator+(pt r) const {
        return pt{x + r.x, y + r.y};
    }
};

int operator%(const pt& a, const pt& b) {
    return a.x * b.y - a.y * b.x;
}

bool par(pt a, pt b, pt c, pt d) {
    return (b - a) % (d - c) == 0;
}

pt a[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    for (int i = 0; i < 3; i++) {
        sci(a[i].x, a[i].y);
    }
    
    set<pt> ans;
    
    sort(a, a + 3);
    do {
        pt t = a[0] - a[1];
        ans.insert(a[2] + t);
        ans.insert(a[2] - t);
    } while (next_permutation(a, a + 3));
    
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i.x << " " << i.y << "\n";
    }
       

    return 0;
}