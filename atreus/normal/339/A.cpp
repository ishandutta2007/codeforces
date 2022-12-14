#include <iostream>

using namespace std;

int main (){
    string s;
    cin >> s;
    char m;
    for (int i = 0; i < s.length(); i += 2){
        for (int j = i + 2; j <= s.length(); j += 2)
            if (s[i] - '0' > s[j] - '0'){
                m = s[i];
                s[i] = s[j];
                s[j] = m;
            }
    }
    for (int i = 0; i < s.length(); i++)
        cout << s[i];
}