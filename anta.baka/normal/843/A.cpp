#include <bits/stdc++.h>

using namespace std;

int n, a[100000], tmp;
map<int, int> pos;
vector<vector<int>> v;
vector<bool> used;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], pos[a[i]];
    for(auto it = pos.begin(); it != pos.end(); it++) it->second = tmp++;
    used.assign(n, false);
    for(int i = 0; i < n; i++)
        if(!used[i]) {
            v.push_back({});
            int x = i;
            while(!used[x]) {
                v.back().push_back(x);
                used[x] = true;
                x = pos[a[x]];
            }
        }
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].size() << ' ';
        for(int j : v[i]) cout << j + 1 << ' ';
        cout << '\n';
    }
}