#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100 * 1000 + 5;
string s[MAXN], ans;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    int k = s[0].length();
    for(int i = 0; i < k; i++) {
        int mask = 0;
        for(int j = 0; j < n; j++)
            if(s[j][i] != '?')
                mask |= (1 << (s[j][i] - 'a'));
        int p = __builtin_popcount(mask);
        if(!p)
            ans += 'a';
        else if(p == 1) {
            for(int j = 0; j < 30; j++)
                if(mask & (1 << j)) {
                    ans += char('a' + j);
                    break;
                }
        }
        else
            ans += '?';
    }
    cout << ans << '\n';
    return 0;
}