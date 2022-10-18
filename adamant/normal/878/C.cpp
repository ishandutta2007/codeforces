#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 42;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    set<pair<int, int>> players[k];
    bitset<maxn> winners;
    int nxt[n][k] = {-1}, prv[n][k] = {-1};
    memset(nxt, -1, sizeof(nxt));
    memset(prv, -1, sizeof(prv));
    int s[n][k];
    for(int i = 0; i < n; i++) {
        bool new_w = (i == 0);
        bool dominate = 1;
        for(int j = 0; j < k; j++) {
            cin >> s[i][j];
            auto it = players[j].insert({s[i][j], i}).first;
            dominate &= it == prev(end(players[j]));
            if(it != begin(players[j])) {
                new_w |= winners[prev(it)->second];
                prv[i][j] = prev(it)->second;
                nxt[prev(it)->second][j] = i;
            }
            if(next(it) != end(players[j])) {
                nxt[i][j] = next(it)->second;
                prv[next(it)->second][j] = i;
            }
        }
        if(dominate) {
            winners = 0;
        }
        if(new_w) {
            winners[i] = 1;
            deque<int> que;
            que.push_back(i);
            while(que.size()) {
                int v = que.front();
                que.pop_front();
                for(int j = 0; j < k; j++) {
                    auto u = nxt[v][j];
                    if(u != -1 && !winners[u]) {
                        winners[u] = 18;
                        que.push_back(u);
                    }
                }
            }
        }
        
        cout << winners.count() << "\n";
    }
}