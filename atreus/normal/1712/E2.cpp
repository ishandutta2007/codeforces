#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int divs[MAXN], l[MAXN], r[MAXN];
int fen[MAXN];
long long answer[MAXN];
vector<int> Query[MAXN];

void add(int idx, int val) {
    for (; idx < MAXN; idx += idx & -idx)
        fen[idx] += val;
}

int get(int idx) {
    int ret = 0;
    for (; idx; idx -= idx & -idx)
        ret += fen[idx];
    return ret;
}

int getDivByK(int l, int r, int k) {
    return max(0, (r / k) - ((l - 1) / k));
}

long long f(int d) {
    return 1LL * (d - 1) * (d - 2) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        Query[l[i]].push_back(i);
        int len = r[i] - l[i] + 1;
        answer[i] = 1LL * len * (len - 1) * (len - 2) / 6;
    }
    int N = 200'000;
    for (int i = N; i >= 1; i--) {
        for (int j = i; j <= N; j += i) {
            if (divs[j] > 0)
                add(j, -f(divs[j]));
            divs[j]++;
            add(j, f(divs[j]));
        }
        for (int q : Query[i])
            answer[q] -= get(r[q]) - get(l[q] - 1);
    }
    for (int i = 1; i <= q; i++) {
        answer[i] -= getDivByK(2 * l[i], r[i], 6);
        answer[i] -= getDivByK((5 * l[i] + 1) / 2, r[i], 15);
        cout << answer[i] << '\n';
    }
}