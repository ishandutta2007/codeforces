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
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            int x = 0, y = 0;
            for (int k = i; k <= j; k++) {
                if (s[k] == 'U')
                    x++;
                if (s[k] == 'D')
                    x--;
                if (s[k] == 'L')
                    y++;
                if (s[k] == 'R')
                    y--;
            }
            if (x == 0 && y == 0)
                ans++;
        }
    cout << ans << endl;
    return 0;
}