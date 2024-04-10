#include <bits/stdc++.h>
using namespace std;

const int C = 100;

int ask(char c, int a) {
    cout << c << ' ' << a << endl;
    if (c == 'C')
        exit(0);
    cin >> a;
    return a;
}

int main () {
    int n;
    cin >> n;
    vector <bool> in_set(n + 1, true);
    in_set[0] = false;
    vector <bool> prime(n + 1, true);
    prime[1] = false;
    vector <int> big_p, small_p;
    for (int i = 2; i <= n; ++i) if (prime[i]) {
        if (1ll * i * i <= n)
            small_p.push_back(i);
        else
            big_p.push_back(i);
        for (int j = i + i; j <= n; j += i)
            prime[j] = false;
    }
    vector <int> block;
    vector <int> prime_factor;
    auto check_block = [&]() {
        int tmp = ask('A', 1);
        if (accumulate(in_set.begin(), in_set.end(), 0) != tmp) {
            for (int i : block) {
                tmp = ask('A', i);
                if (tmp == 1) {
                    prime_factor.push_back(i);
                    return true;
                }
            }
            assert(false);
        }
        block.clear();
        return false;
    };
    int m = big_p.size();
    for (int i = m - 1; ~i; --i) {
        int x = big_p[i];
        block.push_back(x);
        ask('B', x);
        for (int j = x; j <= n; j += x)
            in_set[j] = false;
        if (block.size() == C || i == 0) {
            if (check_block())
                break;
        }
    }
    for (int i : small_p) {
        ask('B', i);
        if (ask('A', i) == 1) {
            prime_factor.push_back(i);
        }
    }
    int ans = 1;
    for (int i : prime_factor) {
        int now = i;
        while (1ll * now * i <= n && ask('A', now * i) == 1)
            now *= i;
        ans *= now;
    }
    ask('C', ans);
}