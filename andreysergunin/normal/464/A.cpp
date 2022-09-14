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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if (p == 1) {
        cout << "NO";
        return 0;
    }
    if (p == 2) {
        if (s == "a") {
            cout << "b";
            return 0;
        }
        if (s == "ab") {
            cout << "ba";
            return 0;
        }
        cout << "NO" << endl;
        return 0;
    }
    string u, v;
    bool f;
    if (s[0] - 'a' == p - 1)
        f = false;
    else {
        f = true;
        u = (s[0] + 1);
    }
    for (int i = 1; i < n; i++) {
        if (s[i] - 'a' < p - 1 && s[i] + 1 != s[i - 1] && (i == 1 || s[i] + 1 != s[i - 2])) {
            u = "";
            for (int j = 0; j < i; j++)
                u += s[j];
            u += (s[i] + 1);
            f = true;
            continue;
        }
        if (s[i] - 'a' < p - 2 && s[i] + 2 != s[i - 1] && (i == 1 || s[i] + 2 != s[i - 2])) {
            u = "";
            for (int j = 0; j < i; j++)
                u += s[j];
            u += (s[i] + 2);
            f = true;
            continue;
        }
        if (s[i] - 'a' < p - 3) {
            u = "";
            for (int j = 0; j < i; j++)
                u += s[j];
            u += (s[i] + 3);
            f = true;
            continue;
        }
        for (int j = 0; j < 3; j++) {
            if (f && u[i - 1] - 'a' != j && (i == 1 || u[i - 2] - 'a' != j)) {
                u += (j + 'a');
                break;
            }
        }
    }
    if (f)
        cout << u << endl;
    else
        cout << "NO";
    return 0;
}