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
    int d, n, m;
    cin >> d >> n >> m;
    vector< pair<long long, long long> > p(m + 2);
    p[0] = make_pair(0, 0);
    for (int i = 1; i <= m; i++)
        cin >> p[i].first >> p[i].second;
    p[m + 1] = make_pair(d, 0);
    sort(p.begin(), p.end());
    
    
    stack<long long> st;
    vector<int> nxt(m + 2);
    for (int i = 0; i <= m + 1; i++) {
        while (!st.empty() && p[st.top()].second > p[i].second) {
            nxt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        nxt[st.top()] = m + 2;
        st.pop();
    }
    
    
    vector<vector<int>> sTable(22);
    for (int i = 0; i < 20; i++)
        sTable[i].resize(m + 2);
    
    for (int i = 0; i < m + 2; i++)
        sTable[0][i] = i;
    for (int k = 1; 1 << k <= m + 2; k++) {
        int i = 1 << k;
        for (int j = 0; j < m + 2; j++) {
            if (j + i / 2 >= m + 2 || p[sTable[k - 1][j]].second < p[sTable[k - 1][j + i / 2]].second)
                sTable[k][j] = sTable[k - 1][j];
            else
                sTable[k][j] = sTable[k - 1][j + i / 2];
        }
    }
    
    int cur = 0;
    long long curN = n;
    int r = 0;
    long long ans = 0;
    while (cur < m + 1) {
        while (r < m + 1 && p[cur].first + n >= p[r + 1].first)
            r++;
        
        if (r == cur) {
            cout << -1;
            return 0;
        }
        if (nxt[cur] != m + 2 && p[cur].first + n >= p[nxt[cur]].first) {
            if (p[cur].first + curN < p[nxt[cur]].first) {
                ans += p[cur].second * (p[nxt[cur]].first - (p[cur].first + curN));
                curN += p[nxt[cur]].first - (p[cur].first + curN);
            }
            curN -= p[nxt[cur]].first - p[cur].first;
            cur = nxt[cur];
            continue;
        }
        
        int u;
        for (u = 0; 1 << (u + 1) < (r + 1) - (cur + 1); u++);
        int x = 0;
        if (p[sTable[u][cur + 1]].second < p[sTable[u][r + 1 - (1 << u)]].second)
            x = sTable[u][cur + 1];
        else
            x = sTable[u][r + 1 - (1 << u)];
        ans += (n - curN) * p[cur].second;
        curN = n;
        curN -= p[x].first - p[cur].first;
        cur = x;
    }
    cout << ans << endl;
    
    return 0;
}