#include <bits/stdc++.h> 

using namespace std;

string s;

int main (int argc, char const *argv[]) {
    cin >> s;
    int sz = s.size();
    char ch = 'a';
    for (int i = 0; i < sz; ++i) {
        if (s[i] > ch) {
            puts("NO");
            return 0;
        }
        if (s[i] == ch) {
            ++ch;
        }
    }
    puts("YES");
    return 0;
}