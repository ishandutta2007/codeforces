#include <bits/stdc++.h>
//#define int long long
#define mp make_pair

using namespace std;

int main() {
    string s;
    int n;
    cin >> n;
    int k = 0;
    cin >> s;
    for (int i = 0; i < s.length() - 1; i++) {
        if(s[i] == s[i + 1]) {
            k++;
        }
    }
    cout << k;
}