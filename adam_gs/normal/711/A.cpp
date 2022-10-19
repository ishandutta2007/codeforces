#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    bool t = false;
    for (int i = 0; i < n; ++i) {
        if (tab[i][0]=='O' && tab[i][1]=='O') {
            tab[i][0]='+';
            tab[i][1]='+';
            t=true;
            break;
        }
        if (tab[i][3]=='O' && tab[i][4]=='O') {
            tab[i][3]='+';
            tab[i][4]='+';
            t=true;
            break;
        }
    }
    if (t==false) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << tab[i] << '\n';
        }
    }
}