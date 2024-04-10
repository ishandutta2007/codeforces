#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = 0, y = 0;
        for(int j = i; j < n; j++) {
            if(s[j] == 'U')
                y++;
            else if(s[j] == 'R')
                x++;
            else if(s[j] == 'D')
                y--;
            else
                x--;
            if(x == 0 && y == 0)
                ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}