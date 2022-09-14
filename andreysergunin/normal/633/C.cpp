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

const int INF = 1e9;

struct node {
    node() {
        for (int i = 0; i < 26; i++)
            link[i] = nullptr;
        t = -1;
    }
    node *link[26];
    int t;
    
};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<string> t(m);
    node *tree = new node;
    for (int i = 0; i < m; i++) {
        cin >> t[i];
        node *cur = tree;
        for (int j = 0; j < t[i].size(); j++) {
            int x = t[i][j] - (t[i][j] <= 'Z' ? 'A' : 'a');
            if (cur->link[x] == nullptr)
                cur->link[x] = new node;
            cur = cur->link[x];
        }
        cur->t = i;
    }
    vector<int> dp(n + 1);
    dp[n] = 0;
    for (int i = 0; i < n; i++)
        dp[i] = -1;
    for (int i = n; i >= 1; i--) {
        if (dp[i] == -1)
            continue;
        node *cur = tree;
        for (int j = i - 1; j >= 0; j--) {
            if (cur->link[s[j] - 'a'] == nullptr)
                break;
            cur = cur->link[s[j] - 'a'];
            if (cur->t != -1)
                dp[j] = cur->t;
        }
    }
    int k = 0;
    for ( ; ; ) {
        if (k >= s.size())
            break;
        cout << t[dp[k]] << " ";
        k += (int)t[dp[k]].size();
    }
    
    return 0;
}