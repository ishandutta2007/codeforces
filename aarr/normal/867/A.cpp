#include <iostream>

using namespace std; int main() { int n; string s; cin >> n; cin >> s; if(s[0] == 'S' && s[n - 1] == 'F') cout << "YES"; else cout << "NO"; }