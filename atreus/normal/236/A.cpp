#include <bits/stdc++.h>

using namespace std;

int main (){
    int cnt = 0;
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n - 1; i++){
        if (s[i] != '0')
            for (int j = i + 1; j < n; j++)
                if (s[i] == s[j]){
                    cnt ++;
                    s[j] = '0';
            }
    }
    n -= cnt;
    if (n % 2 == 1)
        cout << "IGNORE HIM!" << endl;
    else
        cout << "CHAT WITH HER!" << endl;
}