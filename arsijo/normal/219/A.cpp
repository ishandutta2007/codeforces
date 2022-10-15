//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n; 
    cin >> n;
    string s;
    cin >> s;
    //97 122
    int ar[26];
    for(int i = 0; i <= 25; i++){
        ar[i] = 0;
    }
    for(int i = 0; i < s.length(); i++){
        ar[ ( (int) s[i] ) - 97 ] ++;
    }
    string ans = "";
    for(int i = 0; i < 26; i++){
        if (ar[i] % n == 0) {
            for(int j = 0; j < (ar[i] / n); j++){
                ans = ans + (char) (i + 97);
            }
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans;
}