#include <bits/stdc++.h>

using namespace std;

int main() {
    int bbbbb=0;
    char tab[26];
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < 26; ++i) {
        tab[a[i]-'a']=b[i];
    }
    string c;
    cin >> c;
    for (int i = 0; i < c.size(); ++i) {
        if (c[i]<='9') {
            cout << c[i];
        } else if (c[i]<'a') {
            char p = toupper(tab[c[i]-'A']);
            cout << p;
        } else {
            cout << tab[c[i]-'a'];
        }
    }
}