#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int ans = 0;
    int i = 0;
    while(i < (int)s.length()) {
        int j = i;
        while(j < (int)s.length() && s[j] == s[i])
            j++;
        if(!((j - i) & 1))
            ans++;
        i = j;
    }
    cout << ans << '\n';
    return 0;
}