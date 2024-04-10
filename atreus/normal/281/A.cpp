#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    if ((int) s[0] > 90)
        s[0] = s[0] - 'a' + 'A';
    cout << s << endl;
}