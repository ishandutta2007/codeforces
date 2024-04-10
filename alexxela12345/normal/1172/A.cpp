#include <bits/stdc++.h>
#define _ << " " <<
using namespace std; 

const int INF = 1e9;


int lol(vector<int> a, vector<int> b) {
    int n = b.size();
    set<int> aa;
    for (int el : a) {
        aa.insert(el);
    }
    int cur_p = b.size() - 1;
    while (b[cur_p] != 1 && cur_p && b[cur_p - 1] + 1 == b[cur_p]) {
        cur_p--;
    }
    if (aa.count(1) == 0 && b[cur_p] != 1) {
        return INF;
    }
    int ans = cur_p;
    if (b[cur_p] != 1) {
        b.push_back(1);
        ans++;
    }
    cur_p = 0;
    while (b.back() != n) {
        if (aa.count(b.back() + 1) == 0) {
            return INF;
        }
        b.push_back(b.back() + 1);
        aa.insert(b[cur_p++]);
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<int> a, b(n);
    vector<int> pos(n, -1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x) {
            a.push_back(x);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i]) {
            pos[b[i] - 1] = i;
        }
    }
    int kek = lol(a, b);
    if (kek == INF) {
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            if (pos[i] == -1) {
                cnt[i] = 0;
            } else {
                cnt[i] = max(pos[i] - i + 1, 0);
            }
        }
        int maxx = 0;
        for (int el : cnt) {
            maxx = max(maxx, el);
        }
        cout << maxx + n << endl;
    } else {
        cout << kek << endl;
    }
}