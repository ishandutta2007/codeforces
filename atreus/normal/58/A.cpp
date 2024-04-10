#include <bits/stdc++.h>

using namespace std;

int k;

bool have_h(string s){
    for (int i = 0; i < s.length() - 4; i++)
        if (s[i] == 'h'){
            k = i;
            return 1;
        }
    return 0;
}

bool have_e(string s){
    for (int i = k; i < s.length() - 3; i++)
        if (s[i] == 'e'){
            k = i;
            return 1;
        }
    return 0;
}

bool have_l(string s){
    for (int i = k + 1; i < s.length() - 1; i++)
        if (s[i] == 'l'){
            k = i;
            return 1;
        }
    return 0;
}

bool have_o(string s){
    for (int i = k; i < s.length(); i++)
        if (s[i] == 'o'){
            k = i;
            return 1;
        }
    return 0;
}
int main (){
    string s;
    cin >> s;
    if (s.length() <= 4)
        return cout << "NO", 0;
    if (have_h(s) == 0)
        return cout << "NO", 0;
    if (have_e(s) == 0)
        return cout << "NO", 0;
    if (have_l(s) == 0)
        return cout << "NO", 0;
    if (have_l(s) == 0)
        return cout << "NO", 0;
    if (have_o(s) == 0)
        return cout << "NO", 0;
    cout << "YES";
}