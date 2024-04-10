#include <iostream>

using namespace std;

int main (){
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        int cnt = 0;
        for (int j = i + 1; j < i + 7; j++)
            if (s[j] == s[i])
                cnt++;
        if (cnt == 6)
            return cout << "YES", 0;
    }
    cout << "NO" << endl;
}