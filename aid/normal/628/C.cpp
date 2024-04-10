#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    for(int i = 0; i < n; i++) {
        int maxd = 0;
        for(char c = 'a'; c <= 'z'; c++)
            maxd = max(maxd, abs(c - s[i]));
        int need = min(maxd, k);
        for(char c = 'a'; c <= 'z'; c++)
            if(abs(c - s[i]) == need) {
                s[i] = c;
                break;
            }
        k -= need;
    }
    if(k)
        cout << -1 << '\n';
    else
        cout << s << '\n';
    return 0;
}