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
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(3);
    for (int i = 0 ; i < n; i++) {
        if (s[i] == 'R')
            a[0]++;
        if (s[i] == 'G')
            a[1]++;
        if (s[i] == 'B')
            a[2]++;
    }
    vector<int> ans(3);
    for (int i = 0; i < 3; i++) {
        if (a[(i + 1) % 3] > 0 && a[(i + 2) % 3] > 0)
            ans[i] = 1;
        if (a[i] >= 1 && (a[(i + 1) % 3] > 1 || a[(i + 2) % 3] > 1))
            ans[i] = 1;
        if (a[i] >= 1 && a[(i + 1) % 3] == 0 && a[(i + 2) % 3] == 0)
            ans[i] = 1;
    }
    if (ans[2] == 1)
        cout << "B";
    if (ans[1] == 1)
        cout << "G";
    if (ans[0] == 1)
        cout << "R";
    
    
    return 0;
}