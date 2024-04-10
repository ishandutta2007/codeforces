#include <bits/stdc++.h>

class set {
    std::priority_queue<int, std::vector<int>, std::greater<int>> Q, R;
    long long sum;

public:
    set() : sum() {}

    void insert(int x) {
        Q.push(x);
        sum += x;
    }

    void erase(int x) {
        R.push(x);
        sum -= x;
    }

    int top() {
        while (!R.empty() && Q.top() == R.top()) {
            Q.pop();
            R.pop();
        }
        return Q.top();
    }


    std::size_t size() const {
        return Q.size() - R.size();
    }

    long long get_sum() const {
        return sum;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    std::cin >> q;

    const int LG = 30;

    std::vector<set> S(LG);
    while (q--) {
        char op;
        std::cin >> op;
        if (op == '+') {
            int x;
            std::cin >> x;
            int p = std::__lg(x);
            S[p].insert(x);
        } else {
            int x;
            std::cin >> x;
            int p = std::__lg(x);
            S[p].erase(x);
        }
        int ans = 0;
        long long sum = 0;
        for (int i = 0; i < LG; ++i) {
            if (S[i].size()) {
                ans += S[i].size();
                ans -= S[i].top() > 2 * sum;
                sum += S[i].get_sum();
            }
        }
        std::cout << ans << "\n";
    }
}