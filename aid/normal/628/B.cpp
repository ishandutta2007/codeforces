#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if((s[i] - '0') % 4 == 0)
            ans++;
        if(i > 0 && ((s[i - 1] - '0') * 10 + (s[i] - '0')) % 4 == 0)
            ans += i;
    }
    cout << ans << '\n';
    return 0;
}