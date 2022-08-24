#include <bits/stdc++.h>
//#define int long long
#define mp make_pair

using namespace std;

int main() {
    string s;
    cin >> s;
    int k = 0;
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
            k++;
        }
    }
    cout << (k > 0 ? "YES" : "NO");
}