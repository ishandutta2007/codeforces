#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

string a, b;

void load() {
    cin >> a >> b;
}

bool eq(string x, string y) {
    assert(x.size() == y.size());
    if (x.size() % 2) return x == y;
    string s = x, p = y;
    sort(s.begin(), s.end());
    sort(p.begin(), p.end());
    if (s != p) return 0;
    int len = x.size() / 2;
    string x1 = x.substr(0, len);
    string x2 = x.substr(len, len);
    string y1 = y.substr(0, len); 
    string y2 = y.substr(len, len);
    return (eq(x1, y1) && eq(x2, y2)) || (eq(x1, y2) && eq(x2, y1));
}

int main() {
    ios::sync_with_stdio(0);
    load();
    puts(eq(a, b) ? "YES" : "NO");
    return 0;
}