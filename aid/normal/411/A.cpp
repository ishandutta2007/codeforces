#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    if(s.length() < 5) {
        cout << "Too weak\n";
        return 0;
    }
    bool sml = false, bl = false, num = false;
    for(size_t i = 0; i < s.length(); i++)
        if('a' <= s[i] && s[i] <= 'z')
            sml = true;
        else if('A' <= s[i] && s[i] <= 'Z')
            bl = true;
        else if('0' <= s[i] && s[i] <= '9')
            num = true;
    if(sml && bl && num)
        cout << "Correct\n";
    else
        cout << "Too weak\n";
    return 0;
}