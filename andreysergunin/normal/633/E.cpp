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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(n), c(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    
    vector<vector<int>> sTable(22);
    for (int i = 0; i < 22; i++)
        sTable[i].resize(n);
    
    for (int i = 0; i < n; i++)
        sTable[0][i] = c[i];
    for (int k = 1; 1 << k <= n; k++) {
        int i = 1 << k;
        for (int j = 0; j < n; j++)
            sTable[k][j] = min(sTable[k - 1][j], (j + i / 2 < n ? sTable[k - 1][j + i / 2] : 0));
    }
    
    vector<int> nxt(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[st.top()] <= v[i]) {
            nxt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        nxt[st.top()] = n;
        st.pop();
    }
    
    vector<int> a(n);
    for (int i = n - 1; i >= 0; i--) {
        a[i] = min(100 * v[i], c[i]);
        if (nxt[i] == n)
            continue;
        int u;
        for (u = 0; 1 << (u + 1) < nxt[i] - i; u++);
        int x = min(sTable[u][i], sTable[u][nxt[i] - (1 << u)]);
        a[i] = max(a[i], min(a[nxt[i]], x));
    }
    
    sort(a.begin(), a.end());
    double ans = 0;
    double cnk = 1;
    cnk *= (double)m / (n - m + 1);
    for (int i = 0; i < n; i++) {
        cnk *= (double)(n - m - i + 1) / (n - i);
        double cur = (double)a[i] * cnk;
        ans += cur;
    }
    printf("%.9lf", ans);
    
    return 0;
}