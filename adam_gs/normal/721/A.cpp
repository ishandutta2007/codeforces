#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    vector<int>tab;
    int a=0;
    for (int i = 0; i < n; ++i) {
        if (x[i]=='B') {
            ++a;
        } else {
            if (a!=0) {
                tab.push_back(a);
            }
            a=0;
        }
    }
    if (a!=0) {
        tab.push_back(a);
    }
    cout << tab.size() << '\n';
    for (int i = 0; i < tab.size(); ++i) {
        cout << tab[i] << " ";
    }
}