#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> s;
        map<char, int> x;
        for(char c: s) {
            x[c]++;
        }
        if(x['A'] + x['C'] == x['B']) {
            cout << "yEs\n";
        } else {
            cout << "nO\n";
        }
    }
}