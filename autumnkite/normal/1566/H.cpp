#include <bits/stdc++.h>

class linear_basis {
    const int B;
 
    std::vector<int> a, mask, bas;
 
public:
    linear_basis(int _B) : B(_B), a(B), mask(B) {}
 
    std::pair<int, bool> insert(int x) {
        int tmp = x, s = 0;
        for (int i = B - 1; i >= 0; --i) {
            if (x >> i & 1) {
                if (a[i]) {
                    x ^= a[i];
                    s ^= mask[i];
                } else {
                    int v = 1 << bas.size();
                    bas.push_back(tmp);
                    a[i] = x;
                    mask[i] = s ^ v;
                    return std::pair<int, bool>(v, true);
                }
            }
        }
        return std::pair<int, bool>(s, false);
    }
 
    std::vector<int> basis() const {
        return bas;
    }
};

std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        v[i] = i;
    }
    for (int i = 2; i * i <= n; ++i) {
        for (int j = i * i; j <= n; j += i * i) {
            while (v[j] % (i * i) == 0) {
                v[j] /= i;
            }
        }
    }

    std::vector<int> p;
    for (int i = 1; i <= n; ++i) {
        if (v[i] == i) {
            p.push_back(i);
        }
    }
    std::cout << p.size();
    for (int x : p) {
        std::cout << " " << x;
    }
    std::cout << std::endl;

    std::vector<int> f(n + 1);
    for (int x : p) {
        std::cin >> f[x];
    }
    for (int i = 2; i <= n; ++i) {
        if (v[i] == i) {
            f[i] ^= f[1];
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (v[i] == i) {
            for (int j = i + i; j <= n; j += i) {
                if (v[j] == j) {
                    f[j] ^= f[i];
                }
            }
        }
    }
    for (int i = n; i >= 1; --i) {
        if (v[i] == i) {
            for (int j = i + i; j <= n; j += i) {
                if (v[j] == j) {
                    f[i] ^= f[j];
                }
            }
        }
    }

    int lg = std::__lg(n) + 1;

    std::vector<std::pair<int, bool>> st(n + 1);
    std::vector<int> mask(n + 1);
    std::vector<std::vector<int>> b(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i] == i) {
            linear_basis B(lg);
            for (int j = i; j <= n; j += i) {
                if (v[j] == i) {
                    st[j] = B.insert(j);
                }
            }
            mask[i] = B.insert(f[i]).first;
            b[i] = B.basis();
            sum += b[i].size();
        }
    }

    std::vector<int> bitcnt(1 << lg);
    for (int i = 1; i < (1 << lg); ++i) {
        bitcnt[i] = bitcnt[i >> 1] + (i & 1);
    }

    std::vector<int> ch;
    for (int i = 1; i <= n; ++i) {
        if (!st[i].second) {
            ch.push_back(i);
        }
    }

    std::vector<bool> sel(n + 1);
    int tot = 0;
    for (int i : ch) {
        sel[i] = rnd() & 1;
        if (sel[i]) {
            mask[v[i]] ^= st[i].first;
            ++tot;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i] == i) {
            tot += bitcnt[mask[i]];
        }
    }

    while (tot != m) {
        int i = ch[rnd() % ch.size()];
        int tmp = tot;
        if (sel[i]) {
            --tot;
        } else {
            ++tot;
        }
        tot -= bitcnt[mask[v[i]]];
        mask[v[i]] ^= st[i].first;
        tot += bitcnt[mask[v[i]]];
        if (abs(tot - m) <= abs(tmp - m) || !(rnd() % (3 * ch.size()))) {
            sel[i].flip();
        } else {
            mask[v[i]] ^= st[i].first;
            tot = tmp;
        }
    }

    for (int i : ch) {
        if (sel[i]) {
            std::cout << i << " ";
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i] == i) {
            for (int j = 0; j < (int)b[i].size(); ++j) {
                if (mask[i] >> j & 1) {
                    std::cout << b[i][j] << " ";
                }
            }
        }
    }
    std::cout << std::endl;
}
// QwQcOrZ nb!!!