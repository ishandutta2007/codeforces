#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

void operator delete(void*) {}

void ans(string &s) {
    if (int(s.length()) % 2 == 1)
        return;
    
    string s1 = "", s2 = "";
    for (int i = 0; i < int(s.length()) / 2; i++)
        s1 += s[i];
    for (int i = int(s.length()) / 2; i < int(s.length()); i++)
        s2 += s[i];
    
    ans(s1);
    ans(s2);
    
    if (s1 < s2)
        s = s1 + s2;
    else
        s = s2 + s1;
}

int main() {
    string a, b; cin >> a >> b;
    ans(a);
    ans(b);
    
    if (a == b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}