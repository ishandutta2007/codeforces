#include <bits/stdc++.h>

using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    int a = 0, e = 0, u = 0, i = 0, o = 0;
    string s, ans;
    cin >> s;
    int cnt = 0;
    char c1 = '1', c2 = '1', c3 = '1';
    for (int j = 0; j < s.size(); j++){
        if (s[j] - 'a' != 0 && s[j] - 'u' != 0 && s[j] - 'e' != 0 && s[j] - 'i' != 0 && s[j] - 'o' != 0){
            c1 = s[j];
            cnt ++;
        }
        else {
            c1 = '1';
            c2 = '1';
            c3 = '1';
            cnt = 0;
        }
        if (cnt >= 3 && (c1 != c2 || c1 != c3 || c2 != c3)){
            ans += ' ';
            ans += s[j];
            cnt = 1;
            c1 = '1';
            c2 = '1';
            c3 = s[j];
        }
        else{
            ans += s[j];
            if (c2 == '1')
                c2 = c1;
            else if (c3 == '1'){
                c3 = c2;
                c2 = c1;
            }
        }
    }
    cout << ans << endl;
}