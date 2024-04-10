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
    char c;
    vector<int> l(26);
    for ( ; ; ) {
        cin >> c;
        if (c == '}') {
            int ans = 0;
            for (int i = 0; i < 26; i++)
                ans += l[i];
            cout << ans;
            return 0;
        }
        if ('a' <= c && 'c' <= 'z')
            l[c - 'a'] = 1;
    }
    return 0;
}