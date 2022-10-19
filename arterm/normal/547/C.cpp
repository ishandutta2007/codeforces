#include <bits/stdc++.h>

using namespace std;

const int M = 500200;

int n, q, a[M];
vector<int> d[M];
bool used[M];
int cnt[M];
long long ans = 0;
vector<int> primes;
bool active[M];

void sito() {
    for (int j = 0; j < M; ++j)
        d[j].push_back(1);
    for (int i = 2; i < M; ++i)
        if (!used[i]) {
            primes.push_back(i);
            for (int j = i; j < M; j += i) {
                used[j] = true;
                int sz = d[j].size();
                for (int k = 0; k < sz; ++k)
                    d[j].push_back(d[j][k] * i);
                reverse(d[j].begin() + sz, d[j].begin() + 2 * sz);
            }
        }
}

void read() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

long long calc(int x) {
    long long ans = 0;
    for (int i = 1; i < (int) d[x].size(); ++i)
        if (i % 2 == 1)
            ans += cnt[d[x][i]];
        else
            ans -= cnt[d[x][i]];
    return ans;
}

void add(int x, int sign) {
    for (int y : d[x]) {
        cnt[y] += sign;
    }
}

void kill() {
    long long tot = 0;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x;
        --x;
        y = a[x];
        if (active[x]) {
            add(y, -1);
            ans -= calc(y);
            --tot;
        } else {
            ans += calc(y);
            add(y, 1);
            ++tot;
        }
        active[x] = !active[x];
        cout << tot * (tot - 1) / 2 - ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    sito();
    read();
    kill();
    return 0;
}