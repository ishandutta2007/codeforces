#include <iostream>
#include <map>

using namespace std;

map <string, int> g;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i <= 9; i++) {
        string k;
        char c;
        for (int j = 0; j < 10; j++) {
            cin >> c;
            k += c;
        }
        g[k] = i;
    }
    int f = 0;
    for (int i = 0; i < 8; i++) {
        string k;
        for (int j = f; j < f + 10; j++) {
            k += s[j];
        }
        f += 10;
        cout << g[k];
    }
}