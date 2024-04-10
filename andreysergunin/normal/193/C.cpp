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

double EPS = 1e-6;

char c[4][7] = {{'a', 'a', 'a', 'b', 'b', 'b', 'b'},
                {'a', 'a', 'b', 'a', 'b', 'a', 'a'},
                {'a', 'b', 'a', 'a', 'a', 'b', 'a'},
                {'b', 'a', 'a', 'a', 'a', 'a', 'b'}};

double e[7][7] = {{0, 0, 1, 1, 0, 1, 1},
                  {0, 1, 0, 1, 1, 0, 1},
                  {1, 0, 0, 1, 1, 1, 0},
                  {0, 1, 1, 0, 1, 1, 0},
                  {1, 0, 1, 0, 1, 0, 1},
                  {1, 1, 0, 0, 0, 1, 1}};

int main() {
    vector<double> a(6);
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    
    for (int i = 0; i < 6; i++) {
        int k = 0;
        for (k = i; k < 6; k++)
            if (e[k][i] != 0)
                break;
        swap(e[k], e[i]);
        swap(a[k], a[i]);
        
        double c = e[i][i];
        for (int l = 0; l < 7; l++)
            e[i][l] /= c;
        a[i] /= c;
        
        for (int j = i + 1; j < 6; j++) {
            a[j] -= a[i] * e[j][i];
            for (int l = 6; l >= i; l--)
                e[j][l] -= e[i][l] * e[j][i];
        }
    }
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            a[j] -= a[i] * e[j][i];
            e[j][6] -= e[i][6] * e[j][i];
            e[j][i] -= e[i][i] * e[j][i];
        }
    }
    double ans = 1e18;
    vector<double> t(7);
    for (double x = 0; x < 1e6; x += 1) {
        vector<double> cur(7);
        bool f = true;
        double s = x;
        for (int i = 0; i < 6; i++) {
            cur[i] = a[i] - x * e[i][6];
            if (cur[i] < -EPS || cur[i] + EPS - floor(cur[i] + EPS) > 2 * EPS)
                f = false;
            s += cur[i];
        }
        cur[6] = x;
        if (!f)
            continue;
        if (ans > s) {
            ans = s;
            for (int i = 0; i < 7; i++)
                t[i] = cur[i];
        }
    }
    if (ans > 1e17) {
        cout << -1;
        return 0;
    }
    printf("%.0lf\n", ans);
    vector<string> s(4);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < t[i] - EPS; j++)
            for (int k = 0; k < 4; k++)
                s[k] += c[k][i];
    }
    for (int i = 0; i < 4; i++)
        cout << s[i] << endl;
    return 0;
}