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

vector<vector<int>> nxt;


int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0)
            ans++;
    }
    sort(a.begin(), a.end());
    nxt.resize(n);
    
    for (int i = 0; i < n; i++)
        nxt[i].resize(n);
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                nxt[i][j] = -1;
                continue;
            }
            while (k < n - 1 && a[k] < a[i] + a[j])
                k++;
            if (a[i] + a[j] == a[k])
                nxt[i][j] = k;
            else
                nxt[i][j] = -1;
        }
    }
    vector<int> v(n);
    
    ans = max(ans, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (a[i] == 0 && a[j] == 0)
                continue;
            int cur = 2;
            int p = i, q = j;
            vector<int> t;
            v[p] = 1;
            t.push_back(p);
            v[q] = 1;
            t.push_back(q);
            while (nxt[p][q] != -1) {
                int s = nxt[p][q];
                while (s < n && a[nxt[p][q]] == a[s] && v[s] == 1)
                    s++;
                if (s == n || a[nxt[p][q]] != a[s])
                    break;
                v[s] = 1;
                cur++;
                t.push_back(s);
                p = q;
                q = s;
            }
            for (int k = 0; k < t.size(); k++)
                v[t[k]] = 0;
            t.clear();
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}