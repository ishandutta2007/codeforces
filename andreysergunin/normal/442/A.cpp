#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'R')
            a[i] = 0;
        if (s[0] == 'G')
            a[i] = 1;
        if (s[0] == 'B')
            a[i] = 2;
        if (s[0] == 'Y')
            a[i] = 3;
        if (s[0] == 'W')
            a[i] = 4;
        
        b[i] = s[1] - '1';
    }
    int x1[5], y1[5];
    for (int k = 0; k < 5; k++) {
        x1[k] = 0;
        y1[k] = 0;
    }
    for (int k = 0; k < n; k++) {
        x1[a[k]] = 1;
        y1[b[k]] = 1;
    }
    int ans = 100;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            int p = i, q = j;
            int x[5], y[5];
            int u = 0, v = 0;
            int t = 0;
            for (int k = 0; k < 5; k++) {
                x[k] = p % 2;
                p /= 2;
                t += x[k];
            }
            for (int k = 0; k < 5; k++) {
                y[k] = q % 2;
                q /= 2;
                t += y[k];
            }
            for (int k = 0; k < 5; k++) {
                if (x[k] == 1)
                    u++;
                if (y[k] == 1)
                    v++;
            }
            int u1 = 0, v1 = 0;
            for (int k = 0; k < 5; k++) {
                if (x1[k] == 1 && x[k] == 0)
                    u1++;
                if (y1[k] == 1 && y[k] == 0)
                    v1++;
            }
            if (u1 == 1)
                for (int k = 0; k < 5; k++)
                    x[k] = 1;
            if (v1 == 1)
                for (int k = 0; k < 5; k++)
                    y[k] = 1;
            
            bool f = true;
            for (int k = 0; k < n; k++)
                for (int l = 0; l < n; l++)
                    if (a[k] != a[l] || b[k] != b[l]) {
                        if (!((a[k] != a[l] && (x[a[k]] == 1 || x[a[l]] == 1)) ||
                            (b[k] != b[l] && (y[b[k]] == 1 || y[b[l]] == 1))))
                            f = false;
                    }
            if (f)
                ans = min(ans, t);
        }
    }
    cout << ans << endl;
    return 0;
}