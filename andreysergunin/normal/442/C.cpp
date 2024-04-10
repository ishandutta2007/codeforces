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

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set< pair<int, int> > s;
    vector<int> prev(n), next(n);
    for (int i = 0; i < n; i++) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
        s.insert(make_pair(a[i], i));
    
    
    long long ans = 0;
    long long q = 0;
    for (int i = 0; i < n - 2; i++) {
        pair<int, int> p = *(s.lower_bound(make_pair(-1, 0)));
        s.erase(p);
        int u, v;
        if (prev[p.second] != -1) {
            u = a[prev[p.second]];
            next[prev[p.second]] = next[p.second];
        }
        else
            u = 0;
        if (next[p.second] != n) {
            v = a[next[p.second]];
            prev[next[p.second]] = prev[p.second];
        }
        else
            v = 0;
        if (min(u, v) > 0)
            ans += (long long)(min(u, v)) - p.first;
        ans += (p.first - q) * (n - 2 - i);
        q = p.first;
    }
    cout << ans;
    return 0;
}