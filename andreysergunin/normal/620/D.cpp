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
    vector< pair<long long, int> > a(n);
    long long s1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        s1 += a[i].first;
    }
    
    int m;
    cin >> m;
    vector< pair<long long, int> > b(m);
    long long s2 = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i;
        s2 += b[i].first;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector< pair<long long, int> > p, q;
    
    for (int i = 0; i < n; i++) {
        vector< pair<int, int> > c;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                p.push_back(make_pair(a[i].first + a[j].first,
                                         a[i].second * n + a[j].second));
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        vector< pair<int, int> > c;
        for (int j = 0; j < m; j++) {
            if (i != j) {
                q.push_back(make_pair(b[i].first + b[j].first,
                                      b[i].second * m + b[j].second));
            }
        }
    }
    
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    
        
    int u = -1, v = -1, l = 0;
    long long best = abs(s1 - s2);
    
    int k = 0;
    for (int i = 0; i < a.size(); i++) {
        while (k + 1 < b.size() && s1 - 2 * a[i].first - s2 + 2 * b[k + 1].first <= 0)
            k++;
        if (best > abs(s1 - 2 * a[i].first - s2 + 2 * b[k].first)) {
            best = abs(s1 - 2 * a[i].first - s2 + 2 * b[k].first);
            l = 1;
            u = a[i].second;
            v = b[k].second;
        }
        if (k < b.size() - 1 && best > abs(s1 - 2 * a[i].first - s2 + 2 * b[k + 1].first)) {
            l = 1;
            best = abs(s1 - 2 * a[i].first - s2 + 2 * b[k + 1].first);
            u = a[i].second;
            v = b[k + 1].second;
        }
    }
    
    k = 0;
    for (int i = 0; i < p.size(); i++) {
        if (q.size() == 0)
            break;
        while (k + 1 < q.size() && s1 - 2 * p[i].first - s2 + 2 * q[k + 1].first <= 0)
            k++;
        if (best > abs(s1 - 2 * p[i].first - s2 + 2 * q[k].first)) {
            l = 2;
            best = abs(s1 - 2 * p[i].first - s2 + 2 * q[k].first);
            u = p[i].second;
            v = q[k].second;
        }
        if (k < q.size() - 1 && best > abs(s1 - 2 * p[i].first - s2 + 2 * q[k + 1].first)) {
            l = 2;
            best = abs(s1 - 2 * p[i].first - s2 + 2 * q[k + 1].first);
            u = p[i].second;
            v = q[k + 1].second;
        }
    }
    cout << best << endl;
    cout << l << endl;
    if (l == 1)
        cout << u + 1 << " " << v + 1;
    if (l == 2) {
        cout << u / n + 1 << " " << v / m + 1 << endl;
        cout << u % n + 1 << " " << v % m + 1 << endl;
    }
}