#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
string s;
vector<int> a;
int get(vector<int> c) {
    int cnt = 0;
    set< int > pos;
    set <int> g;
    for(int i = 0; i < c.size(); i++) {
        if(c[i] > 1) pos.insert(i);
        else g.insert(i);
    }
    for(int i = 0; i < c.size() + 1; i++) {
        if(pos.size() == 0 && g.size() == 0) return i;
        if(pos.size() == 0) {
            g.erase(g.begin());
            if(g.size() > 0) g.erase(g.begin());
        } else if(g.size() == 0) {
            pos.erase(pos.begin());
        } else {
            if(*pos.begin() < *g.begin()) {
                pos.erase(pos.begin());
            } else {
                int st = *pos.begin();
                c[st]--;
                if(c[st] == 1) {
                    pos.erase(pos.begin());
                    g.insert(st);
                    g.erase(g.begin());
                } else if(*pos.begin() < *g.begin()) {
                    pos.erase(pos.begin());
                } else {
                    g.erase(g.begin());
                }
            }
        }
    }
    return c.size();
}
void solve() {
    cin >> n >> s;
    a.clear();
    for(int i = 0; i < n; ) {
        int j = i;
        while(i < n && s[j] == s[i]) {
            i++;
        }
        a.push_back(i - j);
    }

    cout << get(a) << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}