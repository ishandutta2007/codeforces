#include <iostream>
#include <string>

using namespace std;

const int CS = 11;
char c[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    bool b = true;
    for(size_t i = 0; i < s.length(); i++) {
        bool bb = false;
        for(int j = 0; j < CS; j++)
            if(s[i] == c[j]) {
                bb = true;
                break;
            }
        if(!bb) {
            b = false;
            break;
        }
    }
    if(!b) {
        cout << "NO\n";
        return 0;
    }
    for(size_t i = 0; i < s.length(); i++)
        if(s[i] != s[(int)s.length() - (int)i - 1]) {
            b = false;
            break;
        }
    if(!b) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}