#include <bits/stdc++.h> 

using namespace std;

int n;
string home;
map <string, int> cnt;

int main (int argc, char const *argv[]) {
    cin >> n >> home;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        string from = s.substr(0, 3);
        string to = s.substr(5, 3);
        if (from == home) ++cnt[to];
        else ++cnt[from];
    }
    for (auto it : cnt) {
        if (it.second & 1) {
            puts("contest");
            return 0;
        }
    }
    puts("home");
    return 0;
}