#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, s1, abcxyz;
    abcxyz = "abcdefghijklmnopqrstuvwxyz";
    cin >> s;
    for(int i = 0; i <= s.length(); i++){
        s1 = s;
        for(int j = 0; j < abcxyz.length(); j++){
            s1 = s;
            s1.insert(i, 1, abcxyz[j]);
            string m = "";
            int k = s1.length() - 1;
            for(int r = k; r >= 0; r--){
                m += s1[r];
            }
            if(m == s1){
                cout << m;
                return 0;
            }
        }
    }
    cout << "NA";
}