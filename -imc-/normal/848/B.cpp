#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int w, h;
vector<pair<int, int>> answer;

struct group {
    vector<pair<int, int>> x, y;
    
    void add(int g, int pos, int id) {
        if (g == 1)
            x.emplace_back(pos, id);
        else
            y.emplace_back(pos, id);
    }
    
    void process() {
        sort(all(x));
        sort(all(y));
        
        vector<int> ids;
        for (int i = x.size() - 1; i >= 0; i--)
            ids.push_back(x[i].second);
        for (auto it: y)
            ids.push_back(it.second);
        
        int pos = 0;
        for (auto it: y)
            answer[ids[pos++]] = make_pair(w, it.first);
        for (int i = x.size() - 1; i >= 0; i--)
            answer[ids[pos++]] = make_pair(x[i].first, h);
    }
};

void solve() {
    int n;
    cin >> n >> w >> h;
    
    map<int, group> keymap;
    
    for (int i = 0; i < n; i++) {
        int g, p, t;
        cin >> g >> p >> t;
        
        keymap[p - t].add(g, p, i);
    }
    
    answer.resize(n);
    for (auto& it: keymap)
        it.second.process();
    
    for (int i = 0; i < n; i++)
        cout << answer[i].first << " " << answer[i].second << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}