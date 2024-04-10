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
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<long long> e(n);
    vector< pair<int, long long> > u(n);
    
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> e[i];
        u[i] = make_pair(p[i], e[i]);
    }
    
    sort(u.begin(), u.end());
    
    int x = u[n - k].first;
    
    sort(e.begin(), e.end());
    
    long long ans = 1e18;
    
    if (x + 2 <= n) {
        long long t = 0;
        for (int i = 0; i < x + 2; i++)
            t += e[i];
        ans = min(ans, t);
    }
    
    if (x + 1 <= n) {
        long long t = 1e18;
        int l = 0;
        while (u[l].first != x)
            l++;
        int a = l;
        while (l < n && (u[l].first == x || u[l].first == x + 1))
            l++;
        int b = l;
        
        vector<long long> e1, e2;
        
        for (int i = 0; i < n; i++)
            if (u[i].first == x || u[i].first == x + 1)
                e1.push_back(u[i].second);
        
        for (int i = 0; i < n; i++)
            if (u[i].first != x && u[i].first != x + 1)
                e2.push_back(u[i].second);
        
        sort(e1.begin(), e1.end());
        sort(e2.begin(), e2.end());
        
        vector<long long> f, g;
        f.push_back(0);
        g.push_back(0);
        for (int i = 0; i < (int)e1.size(); i++)
            f.push_back(f[i] + e1[i]);
        for (int i = 0; i < (int)e2.size(); i++)
            g.push_back(g[i] + e2[i]);
        for (int i = max(0, n - k - a + 1); i <= b - a; i++)
            if (0 <= x + 1 - i && x + 1 - i < g.size())
                t = min(t, f[i] + g[x + 1 - i]);
        ans = min(ans, t);
    }
    
    if (x <= n) {
        long long t = 1e18;
        int l = 0;
        while (u[l].first != x - 1 && u[l].first != x)
            l++;
        int a = l;
        while (l < n && (u[l].first == x || u[l].first == x - 1))
            l++;
        int b = l;
        vector<long long> e1, e2;
        
        for (int i = 0; i < n; i++)
            if (u[i].first == x || u[i].first == x - 1)
                e1.push_back(u[i].second);
        
        for (int i = 0; i < n; i++)
            if (u[i].first != x && u[i].first != x - 1)
                e2.push_back(u[i].second);
        
        sort(e1.begin(), e1.end());
        sort(e2.begin(), e2.end());
        
        vector<long long> f, g;
        f.push_back(0);
        g.push_back(0);
        for (int i = 0; i < (int)e1.size(); i++)
            f.push_back(f[i] + e1[i]);
        for (int i = 0; i < (int)e2.size(); i++)
            g.push_back(g[i] + e2[i]);
        for (int i = max(0, n - k - a + 1); i <= b - a; i++)
            if (0 <= x + 1 - i && x - i < g.size())
                t = min(t, f[i] + g[x - i]);
        ans = min(ans, t);
    }
    if (ans == 1e18)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}