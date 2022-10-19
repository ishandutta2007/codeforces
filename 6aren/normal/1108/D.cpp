#include <bits/stdc++.h>

using namespace std;

int n;

string s;

int main() {
    cin >> n >> s;
    //rgb= 012 021 102
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
            if ('R' != s[i - 1] && 'R' != s[i + 1])
                s[i] = 'R';
            if ('G' != s[i - 1] && 'G' != s[i + 1])
                s[i] = 'G';
            if ('B' != s[i - 1] && 'B' != s[i + 1])
                s[i] = 'B';
        }
    }
    if (n != 1 && s[n - 1] == s[n - 2]) {
        cnt++;
        if ('R' != s[n - 2]) s[n - 1] = 'R';
        if ('G' != s[n - 2]) s[n - 1] = 'G';
        if ('B' != s[n - 2]) s[n - 1] = 'B';
    }
    cout << cnt << endl;
    cout << s << endl;
    //cin >> n;
    return 0;
}