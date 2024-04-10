#include <bits/stdc++.h>
//#define int long long
#define mp make_pair

using namespace std;

int main() {
    string s;
    char tek;
    cin >> s;
    tek = s[0];
    int k = 1;
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == tek) {
            k++;
            if (k >= 7) {
                cout << "YES";
                return 0;
            }
        }
        else {
            tek = s[i];
            k = 1;
        }
    }
    cout << "NO";
    return 0;
}