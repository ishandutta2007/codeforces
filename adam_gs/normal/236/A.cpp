#include <bits/stdc++.h>

using namespace std;

int tab[26];

int main() {
    string x;
    cin >> x;
    int r = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (tab[x[i]-'a']==0) {
            ++r;
        }
        tab[x[i]-'a']=1;
    }
    if (r%2==0) {
        cout << "CHAT WITH HER!";
    } else {
        cout << "IGNORE HIM!";
    }
}