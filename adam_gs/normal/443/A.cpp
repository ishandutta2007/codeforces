#include <bits/stdc++.h>

using namespace std;

int tab[26];

int main() {
    int r = 0;
    string x;
    getline(cin, x);
    for (int i = 0; i < x.size(); ++i) {
        if (x[i]>='a' && x[i]<='z') {
            if (tab[x[i]-'a']==0) {
                ++r;
            }
            tab[x[i]-'a']=1;
        }
    }
    cout << r;
}