#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void solve(multiset<int>& dims, multiset<int> &order, int x) {
    auto it = order.lower_bound(x);
    auto it1 = it;
    --it1;
    int dt = *it - *it1;
    int d1 = x - *it1, d2 = *it - x;

    dims.erase(dims.find(dt));
    dims.insert(d1);
    dims.insert(d2);

    order.insert(x);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int Q, N, M;
    cin >> M >> N >> Q;

    multiset<int> dims1, dims2;
    dims1.insert(0);
    dims1.insert(N);
    dims2.insert(0);
    dims2.insert(M);

    multiset<int> order1, order2;
    order1.insert(0);
    order1.insert(N);
    order2.insert(0);
    order2.insert(M);

    while (Q--) {
        char op;
        int x;
        cin >> op >> x;

        if (op == 'H') {
            solve(dims1, order1, x);
        } else {
            solve(dims2, order2, x);
        }

        auto it = dims1.end();
        --it;
        auto it2 = dims2.end();
        --it2;
        cout << 1LL * (*it) * (*it2) << '\n';
    }
}