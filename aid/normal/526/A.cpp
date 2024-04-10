#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    for(int len = 1; len < n; len++)
        for(int i = 0; i + 4 * len < n; i++)
            if(s[i] == '*' && s[i + len] == '*' && s[i + 2 * len] == '*' &&
               s[i + 3 * len] == '*' && s[i + 4 * len] == '*') {
                cout << "yes\n";
                return 0;
            }
    cout << "no\n";
    return 0;
}