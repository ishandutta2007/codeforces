#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int gcd(int a, int b) {
    return (a == 0 ? b : gcd(b % a, a));
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    int g = a[0];
    for (int i = 1; i < n; i++)
        g = gcd(g, a[i]);
    string s, ans;
    
    int m = 0;
    for (int i = 0; i < n; i++)
        if (a[i] / g % 2 == 1)
            m++;
    
    if (!(m == 1 || g % 2 == 0)) {
        cout << 0 << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < a[i]; j++)
                cout << (char) ('a' + i);
        return 0;
    }
    
    m = (g % 2 == 0 ? 2 : 1);
    for (int j = 0; j < n; j++)
        if (a[j] / g * m % 2 == 0)
            for (int k = 0; k < a[j] / g * m / 2 ; k++)
                s += (char) ('a' + j);
    for (int j = 0; j < n; j++)
        if (a[j] / g * m % 2 == 1)
            for (int k = 0; k < a[j] / g * m; k++)
                s += (char) ('a' + j);
    for (int j = n - 1; j >= 0; j--)
        if (a[j] / g * m % 2 == 0)
            for (int k = 0; k < a[j] / g * m / 2; k++)
                s += (char) ('a' + j);
    for (int i = 0; i < g / m; i++)
        ans += s;
    cout << g << endl;
    cout << ans;
    return 0;
}