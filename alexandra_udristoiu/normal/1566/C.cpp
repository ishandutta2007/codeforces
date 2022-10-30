#include<iostream>
#include<cstring>
using namespace std;
int t, n, i, sol, ok;
char s[2][100005];
int main(){
    cin>> t;
    for (; t; t--) {
        cin>> n;
        cin>> s[0] + 1;
        cin>> s[1] + 1;
        sol = 0;
        ok = 0;
        for (i = 1; i <= n; i++) {
            if (s[0][i] != s[1][i]) {
                ok = 0;
                sol += 2;
                continue;
            }
            if (s[0][i] == '1') {
                ok = 1;
                continue;
            }
            if (ok == 1) {
                ok = 0;
                sol += 2;
            } else {
                if (s[0][i + 1] == '1' && s[1][i + 1] == '1') {
                    sol += 2;
                    i++;
                } else {
                    sol++;
                }
            }
        }
        cout<< sol <<"\n";
    }
}