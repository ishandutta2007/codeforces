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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    char a[26];
    for (int i = 0; i < 26; i++)
        a[i] = 'a' + i;
    for (int i = 0; i < m; i++) {
        char f, t;
        cin >> f >> t;
        for (int j = 0; j < 26; j++) {
            if (a[j] == f) {
                a[j] = t;
                continue;
            }
            if (a[j] == t)
                a[j] = f;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[s[i] - 'a'];
}