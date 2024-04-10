#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 200 * 1000 + 5, SIGMA = 26;
const long long P = 131, MOD = 1467212378463281ll;
long long eh;
int pos[SIGMA], post[SIGMA];
pair<long long, int> h[SIGMA], ht[SIGMA];
vector<int> ans;

bool solve() {
    for(int i = 0; i < SIGMA; i++)
        pos[h[i].second] = i;
    for(int i = 0; i < SIGMA; i++)
        post[ht[i].second] = i;
    for(int i = 0; i < SIGMA; i++) {
        if(h[i].first != ht[i].first)
            return false;
        if(h[i].first == eh && ht[i].first == eh)
            continue;
        if(h[i].second == ht[i].second)
            continue;
        if(h[pos[ht[i].second]].first != ht[post[h[i].second]].first)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < m; i++)
        eh = (P * eh + 1) % MOD;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < SIGMA; j++)
            ht[j].first = (P * ht[j].first + 1 + (t[i] - 'a' == j)) % MOD;
    for(int i = 0; i < SIGMA; i++)
        ht[i].second = i;
    sort(ht, ht + SIGMA);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < SIGMA; j++)
            h[j].first = (P * h[j].first + 1 + (s[i] - 'a' == j)) % MOD;
    for(int i = 0; i < SIGMA; i++)
        h[i].second = i;
    sort(h, h + SIGMA);
    if(solve())
        ans.push_back(0);
    long long pp = 1;
    for(int i = 0; i < m - 1; i++)
        pp = P * pp % MOD;
    for(int i = 0; i + m < n; i++) {
        for(int j = 0; j < SIGMA; j++) {
            h[j].first = (P * (h[j].first - pp *
                               (1 + (s[i] - 'a' == h[j].second))) +
                    1 + (s[i + m] - 'a' == h[j].second)) % MOD;
            h[j].first = (h[j].first + MOD) % MOD;
        }
        sort(h, h + SIGMA);
        if(solve())
            ans.push_back(i + 1);
    }
    cout << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}