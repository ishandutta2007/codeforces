/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5;

/*
3 6 5 6 2 1 3

1 2 3 3 5 6 6
*/

#define it multiset<Node>::iterator

struct Node {
    int a, b;
    bool operator<(const Node &rhs) const {
        if (b == rhs.b) return a < rhs.a;
        return b < rhs.b;
    }
} a[N + 10];
multiset<Node> s;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    int n = fr(), cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++) fr(a[i].a), fr(a[i].b), s.insert((Node){a[i].a, a[i].b});
    while (s.size()) {
        it u = s.begin();
        if (u->b > cnt) {
            it v = (--s.end());
            int a = v->a, b = v->b, k = min(a, u->b - cnt);
            s.erase(v), a -= k, ans += (k << 1), cnt += k;
            if (a) s.insert((Node){a, b});
        } else {
            int a = u->a, b = u->b;
            s.erase(u), cnt += a, ans += a;
        }
    }
    return printf("%lld\n", ans), 0;
}

/*
1 5
3 4
1 3
*/

/*
2 + 2 + 1 + 2 + 1 + 1 + 2 + 1
*/
/*
1 8
2 8
2 7
2 4
1 2
*/