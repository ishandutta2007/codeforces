#include<iostream>
#include<cstring>
using namespace std;
int t, n, i, sol;
char s[100005];
int main(){
    cin>> t;
    for (; t; t--) {
        cin>> s;
        n = strlen(s);
        sol = 0;
        for (i = 0; i < n; i++) {
            if (s[i] == '0' && (i == 0 || s[i - 1] != s[i])) {
                sol++;
            }
        }
        sol = min(sol, 2);
        cout<< sol <<"\n";
    }
}