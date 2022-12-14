#include <bits/stdc++.h>

using namespace std;

int main (){
    int st, cnt = 0;
    cin >> st;
    string s;
    cin >> s;
    for (int i = 0; i < st - 1; i++){
        for (int j = i + 1; j < st; j++){
            if (s[i] != s[j])
                break;
            else{
                cnt++;
                s[j] = j * 10;
            }
        }
    }
    cout << cnt << endl;
}