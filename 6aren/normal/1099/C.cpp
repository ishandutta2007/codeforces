#include <bits/stdc++.h>
using namespace std;

string s;

int check[205], k, cntRemov = 0, cntRep = 0;

int main() {
    cin >> s >> k;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != '*' && s[i] != '?' && s[i + 1] != '*' && s[i + 1] != '?') {
            check[i] = 1;
        }
        if (s[i + 1] == '?') {
            check[i] = 2;
            cntRemov++;
        }
        if (s[i + 1] == '*') {
            check[i] = 3;
            cntRemov++;
            cntRep++;
        }
    }
    if (s[s.size() - 1] != '*' && s[s.size() - 1] != '?') check[s.size() - 1] = 1;
    if (k < s.size() - 2 * cntRemov) {cout << "Impossible"; return 0;}
    if (cntRep == 0 && k > s.size() - cntRemov) {cout << "Impossible"; return 0;}
    int si = s.size() - cntRemov;
    if (k <= si) {
        k = si - k;
        for (int i = 0; i < s.size(); i++) {
            if (check[i] == 1) cout << s[i];
            if ((check[i] == 2 || check[i] == 3) && (k == 0)) {
                cout << s[i];
            } else if (check[i] == 2 || check[i] == 3) k--;
        }
    } else if (k > si && cntRep > 0) {
        k = k - si;
        for (int i = 0; i < s.size(); i++) {
            if (check[i]) cout << s[i];
            if (check[i] == 3) {
                while (k != 0) {
                    cout << s[i];
                    k--;
                }
            }
        }
    }
    return 0;
}