#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            if (s[i] < s[j]) swap(s[i], s[j]);
        }
    }
    string ans = "";
    if (s[0] == '1') ans += "1";
    else {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '0') ans += s[i];
    }
    cout << ans;
    return 0;
}