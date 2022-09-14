#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;



int prefixFunction(string s) {
    int n = (int)s.size();
    vector<int> pf(n);
    pf[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pf[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pf[j - 1];
        if (s[i] == s[j])
            j++;
        pf[i] = j;
    }
    return pf[n - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string u, v, s;
    cin >> u >> v;
    for (int i = n - 1; i >= 0; i--) {
        if (u[i] == 'W')
            s += 'E';
        if (u[i] == 'E')
            s += 'W';
        if (u[i] == 'N')
            s += 'S';
        if (u[i] == 'S')
            s += 'N';
    }
    s += 'A';
    for (int i = 0; i < n - 1; i++)
        s += v[i];
    if (prefixFunction(s) > 0)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}