#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s, t = "CODEFORCES";
    cin >> s;
    int n = s.length();
    for(int i = 0; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(s.substr(0, i) + s.substr(j, n - j) == t) {
                cout << "YES\n";
                return 0;
            }
    cout << "NO\n";
    return 0;
}