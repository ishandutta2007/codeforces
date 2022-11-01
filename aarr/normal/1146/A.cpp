#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a')
            x++;
    }
    cout << min(2 * x - 1, (int) s.size());
    return 0;
}