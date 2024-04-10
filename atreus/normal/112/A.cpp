#include <iostream>

using namespace std;

string make_capital(string s){
    for (int i = 0; i < s.length(); i++){
        if ((int) s[i] >= 97)
            s[i] = s[i] - 'a' + 'A';
    }
    return s;
}
int main (){
    string s, a;
    cin >> s >> a;
    s = make_capital(s);
    a = make_capital(a);
    for (int i = 0; i < s.length(); i++){
        if (s[i] - 'A' > a[i] - 'A')
            return cout << "1", 0;
        else if (s[i] - 'A' < a[i] - 'A')
            return cout << "-1", 0;
    }
    cout << 0;
}