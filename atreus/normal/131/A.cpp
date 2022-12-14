#include <bits/stdc++.h>

using namespace std;

string f(string s){
    if ((int) s[0] > 90){
        s[0] = s[0] - 'a' + 'A';
    }
    else
        s[0] = s[0] - 'A' + 'a';
    for (int i = 1; i < s.length(); i++)
        s[i] = s[i] - 'A' + 'a';
    return s;
}
int main (){
    string s;
    cin >> s;
    for (int i = 1; i < s.length(); i++){
        if ((int) s[i] > 90)
            return cout << s, 0;
    }
    cout << f(s);
}