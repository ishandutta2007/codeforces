#include <bits/stdc++.h>

#define real ORLY
#define endl '\n'
#define mp make_pair
#define fc first
#define sc second

using namespace std;

typedef long long ll;

const int MAXN = 200000 + 7;
bitset <MAXN> can[4];
bitset <MAXN> ans;
int event[4];

int p[] = {'A', 'G', 'C', 'T'};
int to[255];

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;
    string s, t;
    cin >> n >> m >> k;
    cin >> s >> t;
    to['A'] = 0;
    to['G'] = 1;
    to['C'] = 2;
    to['T'] = 3;
    for (int i = 0; i <= k; i++) {
        event[to[s[i]]]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (event[j]) {
                can[j][i] = 1;
            }
        }
        if (i - k >= 0) {
            event[to[s[i - k]]]--;
        }
        if (i + k + 1 < n) {
            event[to[s[i + k + 1]]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        ans[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        ans = (ans & (can[to[t[i]]] >> i));
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += ans[i];
    }
    cout << res << endl;
}