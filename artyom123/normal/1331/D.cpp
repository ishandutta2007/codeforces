#include<bits/stdc++.h>

using namespace std;

#define pb push_back

int main() {
    string s;
    cin >> s;
    cout << (s.back() - '0') % 2;
    return 0;
}