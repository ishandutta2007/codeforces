#/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("d.in", "r", stdin); freopen("d.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    getline(cin, s);
    
    int f = 0, I = 0, a = 0;
    for(int i = 0; i < n; i++){
        if (s[i] == 'F')
            f++;
        else if (s[i] == 'I')
            I++;
        else
            a++;
    }
    int ans = 0;
    if (I == 0){
        ans = a;
    }else if (I == 1){
        ans = 1;
    }else{
        ans = 0;
    }
    cout << ans;
}