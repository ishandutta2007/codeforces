#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define MOD 1000000007
#define f first
#define s second

using namespace std;

vector<int> rel[200005];
vector<int> rev[200005];

deque<int> res;
bool used[200005];

void topol(int node) {
    used[node] = true;
    for(int ne : rev[node]) {
        if(!used[ne]) {
            topol(ne);
        }
    }
    res.push_back(node);
}

int state[200005];
bool fail = false;
void find_cycle(int node) {
    state[node] = 1;
    for(int ne : rel[node]) {
        if(state[ne]) {
            if(state[ne] == 1) {
                fail = true;
                break;
            }
        } else {
            find_cycle(ne);
        }
    }
    state[node] = 2;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pi>> nei(n+1);
    map<pi,int> edges;
    for(int i = 0; i < m; i ++) {
        int a, b, r;
        cin >> r >> a >> b; r --;
        int mn = min(a,b);
        int mx = max(a,b);
        auto it = edges.find({mn,mx});
        if(it != edges.end()) {
            if(it->second != r) {
                fail = true;
            }
        } else {
            nei[a].push_back({b,r});
            nei[b].push_back({a,r});
            edges.insert({{mn,mx},r});
        }
    }
    if(fail) {
        cout << "NO";
        return 0;
    }
    vector<bool> visited(n+1);
    vector<int> dir(n+1);
    
    for(int i = 1; i <= n; i ++) {
        if(visited[i]) { continue; }
        visited[i] = true;
        dir[i] = 0;
        deque<int> bfs = {i};
        while(bfs.size()) {
            int curr = bfs.back();
            bfs.pop_back();
            for(pi ne : nei[curr]) {
                if(curr < ne.f) {
                    if(dir[curr] ^ ne.s) {
                        rel[ne.f].push_back(curr);
                        rev[curr].push_back(ne.f);
                    } else {
                        rel[curr].push_back(ne.f);
                        rev[ne.f].push_back(curr);
                    }
                }
                if(!visited[ne.f]) {
                    dir[ne.f] = 1 - dir[curr];
                    visited[ne.f] = true;
                    bfs.push_front(ne.f);
                } else if(dir[ne.f] == dir[curr]) {
                    fail = true;
                    break;
                }
            }
        }
        if(fail) {
            cout << "NO";
            return 0;
        }
    }
    
    for(int i = 1; i <= n; i ++) {
        if(state[i]) { continue; }
        find_cycle(i);
        if(fail) {
            cout << "NO";
            return 0;
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(used[i]) { continue; }
        topol(i);
    }
    vector<int> loc(n+1);
    for(int i = 0; i < n; i ++) {
        int curr = res.front();
        res.pop_front();
        loc[curr] = i;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i ++) {
        cout << (dir[i] ? 'R' : 'L') << " " << loc[i] << "\n";
    }
    return 0;
}