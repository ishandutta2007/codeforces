#include <bits/stdc++.h>
using namespace std;

const int N = 505;

pair<int, int> pre[N][N];
bool pushed[N][N];
int n, k;

int change(vector<int> &state, pair<int, int> pre_st, pair<int, int> pos_st) {
    int num_change = (pre_st.first + k - pos_st.first) / 2;
    vector<int> to_change;
    for (int i = 0; i < n; i++) {
        if (state[i] == 0 && to_change.size() < num_change) to_change.push_back(i);  
    }
    for (int i = 0; i < n; i++) {
        if (state[i] == 1 && to_change.size() < k) to_change.push_back(i);
    }
    cout << "? ";
    for (int e : to_change) {
        state[e] = 1 - state[e];
        cout << e + 1 << ' ';
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    if (n % 2 && k % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) pre[i][j] = {-1, -1};

    queue<pair<int, int>> q;
    q.push({n, 0});
    pushed[n][0] = 1;
    
    while (!q.empty()) {
        auto foo = q.front(); q.pop();
        if (foo == make_pair(0, n)) break;
        int l = foo.first;
        int r = foo.second;
        for (int i = max(0, k - foo.second); i <= min(k, foo.first); i++) {
            int u = l - i + (k - i);
            int v = r + i - (k - i);
            if (pushed[u][v]) continue;
            pre[u][v] = foo;
            q.push({u, v});
            pushed[u][v] = true;
        }
    }

    vector<pair<int, int>> moves;
    pair<int, int> cur = {0, n};

    // res.push_back(cur);
    while (cur.first != -1) {
        moves.push_back(cur);
        cur = pre[cur.first][cur.second];
    }

    // cout << prev[0][5] << endl;

    vector<int> state(n, 0);

    reverse(moves.begin(), moves.end());

    int ans = 0;

    for (int i = 1; i < moves.size(); i++) {
        ans ^= change(state, moves[i - 1], moves[i]);
    }

    cout << "! " << ans << endl;

    return 0;
}