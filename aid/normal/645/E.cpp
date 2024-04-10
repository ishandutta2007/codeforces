#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int SIGMA = 30, MOD = 1000 * 1000 * 1000 + 7;
int cnt[SIGMA], pos[SIGMA];
pair<int, int> p[SIGMA];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string t;
    cin >> n >> k >> t;
    int m = t.length(), sum = 1;
    for(int i = 0; i < k; i++)
        pos[i] = -1;
    for(int i = 0; i < m; i++) {
        int id = t[i] - 'a';
        pos[id] = i;
        int newSum = (2 * sum % MOD + MOD - cnt[id]) % MOD;
        cnt[id] = sum;
        sum = newSum;
    }
    for(int i = 0; i < k; i++)
        p[i] = make_pair(pos[i], i);
    sort(p, p + k);
    for(int i = 0; i < n; i++) {
        int id = p[i % k].second, newSum = (2 * sum % MOD + MOD - cnt[id]) % MOD;
        cnt[id] = sum;
        sum = newSum;
    }
    cout << sum << '\n';
    return 0;
}