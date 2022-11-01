#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

string init = "What are you doing at the end of the world? Are you busy? Will you save us?";

string v[3] = {
    "What are you doing while sending \"",
    "\"? Are you busy? Will you send \"",
    "\"?",
};

const int64_t LINF = 1LL << 61;
vector<int64_t> lengths;

void precalc(int n) {
    lengths = vector<int64_t>(n);
    lengths[0] = init.length();
    for (int i = 1; i < n; ++i) {
        lengths[i] = v[0].length() + v[1].length() + v[2].length();
        lengths[i] = min(lengths[i] + lengths[i - 1], LINF);
        lengths[i] = min(lengths[i] + lengths[i - 1], LINF);
    }
}

char solve(int n, int64_t k) {
    if (n == 0) {
        return init[k];
    }

    if (k < SZ(v[0])) {
        return v[0][k];
    }
    k -= SZ(v[0]);
    if (k < lengths[n - 1]) {
        return solve(n - 1, k);
    }
    k -= lengths[n - 1];
    if (k < SZ(v[1])) {
        return v[1][k];
    }
    k -= SZ(v[1]);
    if (k < lengths[n - 1]) {
        return solve(n - 1, k);
    }
    k -= lengths[n - 1];
    if (k < SZ(v[2])) {
        return v[2][k];
    }
    cerr << n << ' ' << k << endl;
    throw;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    precalc(100005);

    int q;
    cin >> q;

    while (q-- > 0) {
        int n;
        int64_t k;
        cin >> n >> k;
        k--;
        if (k >= lengths[n]) {
            cout << ".";
            continue;
        }

        cout << solve(n, k);
    }
    cout << '\n';
}