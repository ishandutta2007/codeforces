#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>
#include <unordered_set>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

char good[33];
int k;

struct Node {
    Node* to[33];

    Node() {
        memset(to, 0, sizeof(to));
    }
};

void add(Node* t, string& s, int i) {
    if (i >= s.length()) {
        return;
    }
    int c = s[i] - 'a';
    Node* n = t->to[c];
    if (n == 0) {
        t->to[c] = n = new Node();
    }
    add(n, s, i + 1);
}

int dfs(Node* t, int cb) {
    if (!t || cb > k) {
        return 0;
    }
    int res = 1;
    for (int i = 0; i < 26; i++) {
        res += dfs(t->to[i], cb + (good[i] == '0' ? 1 : 0));
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    scanf("%s", good);
    sci(k);
    int n = s.length();

    Node* root = new Node();
    for (int i = 0; i < n; i++) {
        add(root, s, i);
    }

    cout << dfs(root, 0) - 1;

    return 0;
}