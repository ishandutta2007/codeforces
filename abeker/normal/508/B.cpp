#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string s;

void load() {
    cin >> s;
}

int odd(char x) { return (x - '0') % 2; }

void solve() {
    N = s.size();
    string sol = "";
    int pos = -1, last = -1;
    for (int i = 0; i < N - 1; i++) {
        if (odd(s[i])) continue;
        if (s[i] != s[N - 1]) last = i;
        if (s[i] < s[N - 1]) {
            pos = i; break;
        }
    }
    if (pos == -1) pos = last;
    if (pos != -1) {
        string a = s;
        swap(a[N - 1], a[pos]);
        if (a > sol) sol = a;
    }
    if (!odd(s[N - 1]) && N > 2) {
        string b = s;
        int idx = N - 2, best = N - 2;
        for (int i = N - 2; i >= 0; i--) {
            if (s[i] < s[idx]) best = i;
            if (s[i] > s[idx]) idx = i;
        }
        if (best == N - 2) {
            idx = -1;
            for (int i = N - 2; i >= 0; i--) 
                if (s[i] > s[best]) { 
                    idx = i; break;
                }
        }
        if (idx != -1) {
            swap(b[idx], b[best]);
            if (b > sol) sol = b;
        }
    }
    if (sol == "") sol = "-1";
    cout << sol << endl;
}

int main() {
    load();
    solve();
    return 0;
}