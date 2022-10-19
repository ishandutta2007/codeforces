#include <bits/stdc++.h>

using namespace std;

int tab[10];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i]=='L') {
            int l = 0;
            while (tab[l]==1)++l;
            tab[l]=1;
        } else if (s[i]=='R') {
            int l = 9;
            while (tab[l]==1)--l;
            tab[l]=1;
        } else {
            tab[s[i]-'0']=0;
        }
    }
    for (int i = 0; i < 10; ++i) {
        cout << tab[i];
    }
}