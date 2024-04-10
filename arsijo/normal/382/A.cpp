
 //============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <bits/stdc++.h>
using namespace std;


int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    string s, s1, s2;
    cin >> s;
    s1 = "";
    s2 = "";
    bool b = true;
    for (int i = 0; i < s.length(); i++){
        if(s[i] == '|'){
            b = false;
        }else{
            if (b){
                s1 = s1 + s[i];
            }else{
                s2 = s2 + s[i];
            }
        }
    }
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if (s1.length() < s2.length()){
            s1 = s1 + s[i];
        }else{
            s2 = s2 + s[i];
        }
    }

    if (s1.length() == s2.length()){
        cout << s1 << '|' << s2;
    }else{
        cout << "Impossible";
    }

}