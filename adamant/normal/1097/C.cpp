#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int maxn = 5e5 + 42;

int cntl[maxn], cntr[maxn];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        int suml = 0, sumr = 0;
        bool canl = true, canr = true;
        for(size_t j = 0; j < s[i].size(); j++) {
            suml += s[i][j] == '(' ? 1 : -1;
            sumr += s[i][s[i].size() - j - 1] == ')' ? 1 : -1;
            canl &= suml >= 0;
            canr &= sumr >= 0;
        }
        if(canl) {
            cntl[suml]++;
        }
        if(canr) {
            cntr[sumr]++;
        }
        if(suml == sumr) {
            
        }
    }
    int ans = cntl[0] / 2;
    for(int i = 1; i < maxn; i++) {
        ans += min(cntl[i], cntr[i]);
    }
    cout << ans << endl;
    return 0;
}