#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char s[] = { 'A', 'W', 'T', 'Y', 'U', 'I', 'O', 'A', 'H', 'X', 'V', 'M' };

bool good(char ch){
    for (int i = 0; i < 12; ++i)
    if (ch == s[i])
        return 1;
    return 0;
}

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    string s;
    cin >> s;
    int l = 0, r = s.length() - 1;

    while (l <= r){
        if (!good(s[l]) || s[l] != s[r]){
            cout << "NO\n";
            return 0;
        }
        ++l;
        --r;
    }

    cout << "YES\n";

    return 0;
}