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
    string s, t;
    int n;
    cin >> n;
    cin >> s;
    cin >> t;
    int a[26][26];
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            a[i][j] = -1;
    int d = 0;
    for (int i = 0; i < n; i++) {
        a[s[i] - 'a'][t[i] - 'a'] = i;
        if (s[i] != t[i])
            d++;
    }
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++) {
            if (i == j)
                continue;
            if (a[i][j] != -1 && a[j][i] != -1) {
                cout << d - 2 << endl;
                cout << a[i][j] + 1 << " " << a[j][i] + 1 << endl;
                return 0;
            }
        }
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++) {
            if (i != j && a[i][j] != -1) {
                for (int k = 0; k < 26; k++)
                    if (a[k][i] != -1 && k != i) {
                        cout << d - 1 << endl;
                        cout << a[i][j] + 1 << " " << a[k][i] + 1 << endl;
                        return 0;
                    }
            }
        }
    cout << d << endl;
    cout << -1 << " " << -1;
    return 0;
    
}