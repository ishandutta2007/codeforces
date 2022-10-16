#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> v(s.length());
    for(int i = 0; i < s.length() - 1; i++)
        if(s[i] == s[i + 1])
            v[i + 1] = v[i] + 1;
        else
            v[i + 1] = v[i];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << v[--r] - v[--l] << '\n';
    }
}