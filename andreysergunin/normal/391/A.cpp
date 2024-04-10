#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k = 1;
    int ans = 0;
    for (int i = 1; i <= (int)s.size(); i++) {
        if (i < (int)s.size() && s[i] == s[i - 1])
            k++;
        else {
            if (k % 2 == 0)
                ans++;
            k = 1;
        }
    }
    cout << ans << endl;
    return 0;
}