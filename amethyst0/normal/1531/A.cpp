#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string ans = "blue";
    cin >> n;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "lock") {
            ok = false;
        } else if (s == "unlock") {
            ok = true;
        } else if (ok) {
            ans = s;
        }
    }
    cout << ans << '\n';
}