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
    int n, m;
    cin >> n >> m;
    vector<int> a, d, c(m);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int str;
        cin >> str;
        if (s == "ATK")
            a.push_back(str);
        else
            d.push_back(str);
    }
    for (int i = 0; i < m; i++)
        cin >> c[i];
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    sort(c.begin(), c.end());
    int p = (int)a.size();
    int q = (int)d.size();
    int ans = 0;
    for (int i = 0; i < min(p, m); i++) {
        int cur = 0;
        bool f = true;
        for (int j = 0; j <= i; j++) {
            if (a[j] > c[m - i + j - 1])
                f = false;
            cur += c[m - i + j - 1] - a[j];
        }
        if (f)
            ans = max(ans, cur);
    }
    
    vector<int> u(m);
    int k = 0;
    for (int i = 0; i < q; i++) {
        while (k < m && c[k] <= d[i])
            k++;
        if (k == m) {
            cout << ans << endl;
            return 0;
        }
        u[k] = 1;
        k++;
    }
    
   
    k = m - 1;
    for (int j = p - 1; j >= 0; j--) {
        while (k >= 0 && (a[j] > c[k] || u[k] == 1))
            k--;
        if (k < 0) {
            cout << ans << endl;
            return 0;
        }
        k--;
    }
    
    int cur = 0;
    for (int i = 0; i < m; i++)
        if (u[i] == 0)
            cur += c[i];
    for (int i = 0; i < p; i++)
        cur -= a[i];
    ans = max(ans, cur);
    cout << ans << endl;
    
    return 0;
}