#include <bits/stdc++.h>

using namespace std;

string a;

string f(string s){
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B'){
            i += 2;
            int x = a.length();
            if (a[x - 1] != ' ' && x != 0)
                a += " ";
        }
        else
            a += s[i];
    }
    return a;
}
int main (){
    string s;
    cin >> s;
    cout << f(s);
}