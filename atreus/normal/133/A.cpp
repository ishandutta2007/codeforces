#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9'/* || s[i] == '+'*/)
            return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;
}