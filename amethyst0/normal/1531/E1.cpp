#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

const int maxn = (int)1e5 + 10;
vector <int> ed[maxn];
string s;
int pos;
vector <int> v;
vector <int> b;

bool my_sort(int l, int r) {
    if (r - l <= 1) {
        return true;
    }
    
    int m = (l + r) >> 1;
    if (!my_sort(l, m)) {
        return false;
    }
    if (!my_sort(m, r)) {
        return false;
    }
    
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (pos == (int)s.size()) {
            return false;
        }
        if (s[pos] == '0') {
            ed[v[j]].push_back(v[i]);
            b[k++] = v[i++];
        } else {
            ed[v[i]].push_back(v[j]);
            b[k++] = v[j++];
        }
        pos++;
    }
    
    while (i < m) {
        b[k++] = v[i++];
    }
    
    while (j < r) {
        b[k++] = v[j++];
    }
    
    for (int i = l; i < r; i++) {
        v[i] = b[i];
    }
    return true;
}

bool used[maxn];
int posit = 0;
int ans[maxn];

void dfs(int v) {
    if (used[v]) {
        return;
    }
    
    used[v] = true;
    for (int u : ed[v]) {
        dfs(u);
    }
    ans[v] = posit++;
}

int main() {
    cin >> s;
    for (int n = 1; n < 1000; n++) {
        v.resize(n);
        for (int i = 0; i < n; i++) {
            v[i] = i;
            ed[i].clear();
        }
        b.resize(n);
        
        pos = 0;
        if (!my_sort(0, n)) {
            continue;
        }
        if (pos != (int)s.size()) {
            continue;
        }
        
        cout << n << '\n';
        for (int i = 0; i < n; i++) {
            dfs(i);
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i] + 1);
        }
        break;
    }
}