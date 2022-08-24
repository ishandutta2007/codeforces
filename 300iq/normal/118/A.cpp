#include <bits/stdc++.h>

using namespace std;

int main()
{
    //    ,
    //      ".",
    //      
    // "A", "O", "Y", "E", "U", "I" - 
    string g = "aoyeuiAOYEUIaoyeuiAOYEUI";
    string s;
    cin >> s;
    bool flag = false;
    for(int i = 0; i < s.length(); i++){
        for(int t = 0; t < g.length(); t++){
            if(s[i] == g[t]){
                s.erase(s.begin() + i);
                t = 0;
            }
        }
    }
   for(int i = 0; i < s.length(); i++){
        if(s[i] != '.'){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] + 32;
            }
            cout << '.';
            cout << s[i];
            s[i] = '.';
        }
   }
}