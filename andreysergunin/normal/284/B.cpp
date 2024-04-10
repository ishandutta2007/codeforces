#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'F')
            a++;
        if (s[i] == 'A')
            b++;
        if (s[i] == 'I')
            c++;
    }
    if (c == 0)
        cout << b;
    else {
        if (c == 1)
            cout << 1;
        else
            cout << 0;
    }
    return 0;
    
            
}