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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> next(n);
    for (int i = 0; i < n; i++)
        next[i] = i + 1;
    vector<int> k;
    vector<int> d(n);
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            k.push_back(i);
    int ans = 0;
    while (k.size() != 0) {
        ans++;
        for (int i = (int)k.size() - 1; i >= 0; i--) {
            d[next[k[i]]] = 1;
            next[k[i]] = next[next[k[i]]];
        }
        vector<int> newk;
        for (int i = 0; i < k.size(); i++)
            if (d[k[i]] == 0 && next[k[i]] < n && a[k[i]] > a[next[k[i]]])
                newk.push_back(k[i]);
        k.clear();
        for (int i = 0; i < newk.size(); i++)
            k.push_back(newk[i]);
    }
    cout << ans << endl;
            
}