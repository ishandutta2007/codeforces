#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    for (int i = 1; i <= t; i++){
        for (int j = 0; j < n; j++){
            if (s[j] == 'B' && s[j + 1] == 'G'){
                char k = s[j];
                s[j] = s[j + 1];
                s[j + 1] = k;
                j++;
            }
        }
    }
    cout << s << endl;
}