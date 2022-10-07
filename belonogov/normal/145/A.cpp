#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>


using namespace std;
string s1,s2;

int main(){
    int n, i, d = 0, kol = 0;
    cin >> s1;
    cin >> s2;
    n = s1.length();
    for (i = 0; i < n; i++){
        if (s1[i] != s2[i])
            kol++;
        if (s1[i] == '7')
            d++;
        if (s2[i] == '7')
            d--;
    }
    if (d < 0)
        d = -d;
    cout << d + (kol - d) / 2;

}