#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '4' || s[i] == '7')
            cnt++;
    if (cnt == 0)
        return cout << "NO", 0;
    while (cnt > 0){
        int indice = cnt % 10;
        if (indice != 4 && indice != 7)
            return cout << "NO", 0;
        cnt /= 10;
    }
    cout << "YES" << endl;

}