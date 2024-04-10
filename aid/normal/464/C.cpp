#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100 * 1000 + 5, D = 10, MOD = 1000 * 1000 * 1000 + 7;
int d[MAXN], len[D], hash[D];
string t[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> d[i];
        char c;
        cin >> c >> c;
        getline(cin, t[i]);
    }
    for(int i = 0; i < D; i++) {
        len[i] = 10;
        hash[i] = i;
    }
    for(int i = n - 1; i >= 0; i--) {
        int newLen = 1, newHash = 0;
        for(size_t j = 0; j < t[i].length(); j++) {
            int dd = t[i][j] - '0';
            newLen = ((long long)newLen * len[dd]) % MOD;
            newHash = ((long long)newHash * len[dd] + hash[dd]) % MOD;
        }
        len[d[i]] = newLen;
        hash[d[i]] = newHash;
    }
    int ans = 0;
    for(size_t i = 0; i < s.length(); i++)
        ans = ((long long)ans * len[s[i] - '0'] + hash[s[i] - '0']) % MOD;
    cout << ans << '\n';
    return 0;
}