#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 1e6 + 10;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    char s[MAXN], t[MAXN];
    scanf("%s", s);
    scanf("%s", t);
    int e1 = (int)strlen(s);
    int e2 = (int)strlen(t);
    int b1 = 0, b2 = 0;
    while (b1 < e1 && s[b1] == '0')
        b1++;
    while (b2 < e2 && t[b2] == '0')
        b2++;
    if (e1 - b1 > e2 - b2) {
        cout << '>';
        return 0;
    }
    if (e1 - b1 < e2 - b2) {
        cout << '<';
        return 0;
    }
    for (; b1 < e1; b1++, b2++) {
        if (s[b1] > t[b2]) {
            cout << '>';
            return 0;
        }
        
        if (s[b1] < t[b2]) {
            cout << '<';
            return 0;
        }
    }
    
    cout << '=';
    
    return 0;
}