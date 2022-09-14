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

const int INF = 1e9;

vector< vector<int> > e;

vector<int> pre, num;

int minSpanningTree(int n) {
    vector<int> v(n), dist(n);
    for (int i = 0; i < n; i++)
        v[i] = 0;
    v[0] = 1;
    for (int i = 0; i < n; i++)
        dist[i] = e[0][i];
    for (int i = 0; i < n; i++)
         pre[i] = 0;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int cur = INF, k = -1;
        for (int j = 0; j < n; j++)
            if (v[j] == 0 && dist[j] < cur) {
                cur = dist[j];
                k = j;
            }
        ans += dist[k];
        v[k] = 1;
        num[i] = k;
        for (int j = 0; j < n; j++)
            if (v[j] == 0 && dist[j] > e[k][j]) {
                dist[j] = e[k][j];
                pre[j] = k;
            }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<char> a[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j].resize(k);
    for (int q = 0; q < k; q++)
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                a[i][j][q] = s[j];
        }
    e.resize(k + 1);
    for (int i = 0; i < k + 1; i++)
        e[i].resize(k + 1);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            int t = 0;
            for (int u = 0; u < n; u++)
                for (int v = 0; v < m; v++)
                    if (a[u][v][i] != a[u][v][j])
                        t++;
            e[i + 1][j + 1] = w * t;
        }
    e[0][0] = 0;
    for (int i = 1; i < k + 1; i++) {
        e[i][0] = n * m;
        e[0][i] = n * m;
    }
    
    pre.resize(k + 1);
    num.resize(k + 1);
    
    cout << minSpanningTree(k + 1) << endl;
    
    for (int i = 1; i <= k; i++)
        cout << num[i] << " " << pre[num[i]] << endl;
    cout << endl;
    return 0;
}