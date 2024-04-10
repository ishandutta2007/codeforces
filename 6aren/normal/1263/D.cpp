#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 200005;

string s;
set<char> ss[N];
vi v[30];
int p[N];

int find(int x) {
    if (p[x] == x) return x;
    return (p[x] = find(p[x]));
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    p[x] = y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cin >> s;
        for (auto u : s) {
            ss[i].insert(u);
        }
        for (auto u : ss[i]) {
            v[u - 'a'].pb(i);
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j < v[i].size(); j++) {
            merge(v[i][j], v[i][j - 1]);
        }
    }
    set<int> ans;
    for (int i = 1; i <= n; i++) ans.insert(find(i));
    cout << ans.size();
    return 0;
}