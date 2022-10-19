#include <bits/stdc++.h>

using namespace std;

int tab[26];

int main() {
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); ++i) {
        ++tab[a[i]-'A'];
    }
    cin >> a;
    for (int i = 0; i < a.size(); ++i) {
        ++tab[a[i]-'A'];
    }
    cin >> a;
    for (int i = 0; i < a.size(); ++i) {
        --tab[a[i]-'A'];
    }
    bool t = true;
    for (int i = 0; i < 26; ++i) {
        if (tab[i]!=0) {
            t=false;
        }
    }
    if (t==true) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}