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
    string s;
    cin >> s;
    int n = (int)s.size();
    for (; ;) {
        int l = 0;
        int pos = 0;
        bool f = false;;
        for (int i = 1; i <= n / 2; i++) {
            int k = 0;
            for (int j = 0; j <= n - 2 * i; j++) {
                while (k < i && s[j + k] == s[j + i + k])
                    k++;
                if (k == i) {
                    l = i;
                    pos = j;
                    f = true;
                    break;
                }
                k = max(k - 1, 0);
            }
            if (f)
                break;
        }
        if (!f)
            break;
        for (int j = pos + l; j < n - l; j++)
            s[j] = s[j + l];
        n -= l;
    }
    for (int i = 0; i < n; i++)
        cout << s[i];
}