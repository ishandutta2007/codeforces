#include <bits/stdc++.h>

using namespace std;

int tab[6];

int main() {
    int n;
    cin >> n;
    int p=n;
    while (n--) {
        string x;
        cin >> x;
        if (x=="purple") tab[0]=1;
        if (x=="green") tab[1]=1;
        if (x=="blue") tab[2]=1;
        if (x=="orange") tab[3]=1;
        if (x=="red") tab[4]=1;
        if (x=="yellow") tab[5]=1;
    }
    cout << 6-p << '\n';
    if (tab[0]==0) {
        cout << "Power\n";
    }
    if (tab[1]==0) {
        cout << "Time\n";
    }
    if (tab[2]==0) {
        cout << "Space\n";
    }
    if (tab[3]==0) {
        cout << "Soul\n";
    }
    if (tab[4]==0) {
        cout << "Reality\n";
    }
    if (tab[5]==0) {
        cout << "Mind\n";
    }
}