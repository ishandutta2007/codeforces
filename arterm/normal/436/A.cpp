#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>

using namespace std;

#define M 2014

int n, x;
vector<pair<int,int> > g[M];

void read(void){
    cin >> n >> x;
    for (int i = 0, t, y, m; i < n; ++i){
        cin >> t >> y >> m;
        g[y].push_back(make_pair(t, m));
    }
}

int kill(int t){
    priority_queue<int> q[2];
    int l = 0;
    while (l <= x && l < M){
        for (auto &x : g[l])
            q[x.first].push(x.second);
        ++l;
    }

    int sum = x;
    int ans = 0;
    while (!q[t].empty()){
        sum += q[t].top();
        q[t].pop();
        ++ans;

        while (l <= sum && l < M){
            for (auto &x : g[l])
                q[x.first].push(x.second);
            ++l;
        }
        t = 1 - t;
    }
    return ans;
}

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();

    int ans = max(kill(0), kill(1));

    cout << ans << "\n";

    return 0;
}