#include <bits/stdc++.h>

const int N = 200000;

bool prime[N + 1];

void init() {
    for (int i = 1; i <= N; ++i) {
        prime[i] = true;
    }
    prime[1] = false;
    for (int i = 2; i <= N; ++i) {
        if (prime[i]) {
            for (int j = i + i; j <= N; j += i) {
                prime[j] = false;
            }
        }
    }
}

void solve() {
    int n;
    std::cin >> n;

    auto lcm = [&](int a, int b) {
        return 1ll * a * b / std::__gcd(a, b);
    };

    auto query = [&](int x, int y) {
        std::cout << "? " << x + 1 << " " << y + 1 << std::endl;
        long long res;
        std::cin >> res;
        return res;
    };

    auto send_ans = [&](const auto &a) {
        std::cout << "!";
        for (int x : a) {
            std::cout << " " << x;
        }
        std::cout << std::endl;
        return;
    };

    if (n == 3) {
        long long a = query(0, 1), b = query(1, 2), c = query(0, 2);
        for (int l = 1; l <= N; ++l) {
            std::vector<int> p(3);
            p[0] = l, p[1] = l + 1, p[2] = l + 2;
            do {
                if (lcm(p[0], p[1]) == a && lcm(p[1], p[2]) == b && lcm(p[0], p[2]) == c) {
                    send_ans(p);
                    return;
                }
            } while (std::next_permutation(p.begin(), p.end()));
        }
        return;
    }

    if (n <= 100) {
        std::vector<std::vector<long long>> s(n, std::vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                s[i][j] = s[j][i] = query(i, j);
            }
        }
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = 0;
            for (int j = 0; j < n; ++j) {
                a[i] = std::__gcd(a[i], s[i][j]);
            }
        }
        send_ans(a);
        return;
    }

    std::mt19937 rnd(std::chrono::system_clock().now().time_since_epoch().count());
    int mx = 0, id = -1;
    int qcnt = 0;
    while (qcnt < 5000) {
        int i = rnd() % n;
        int c = 0;
        long long g = 0;
        while (c < 20 && qcnt < 5000 && (g > N || !prime[g])) {
            int j;
            do {
                j = rnd() % n;
            } while (i == j);
            g = std::__gcd(g, query(i, j));
            ++c;
            ++qcnt;
        }
        if (g <= N && prime[g] && g > mx) {
            mx = g, id = i;
        }
    }
    std::vector<int> a(n);
    a[id] = mx;
    for (int i = 0; i < n; ++i) {
        if (i != id) {
            a[i] = query(i, id) / a[id];
        }
    }
    send_ans(a);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    init();
    
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}