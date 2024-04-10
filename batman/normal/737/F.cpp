#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <tuple>
#include <map>
#include <deque>

using namespace std;
using ll = long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

int n, up;
int B[2];
deque<int> v[3];

using P = pair<int, int>;
vector<P> que;

void move(int id, int c) {
    //cout << id+1 << " " << c << endl;
    if (c > B[id] || int(v[id].size()) < c) {
        throw 1;
    }
    que.push_back(P(id+1, c));
    deque<int> buf;
    for (int i = 0; i < c; i++) {
        buf.push_front(v[id].front());
        v[id].pop_front();
    }
    for (int i = 0; i < c; i++) {
        v[id+1].push_front(buf.front());
        buf.pop_front();
    }
}

void dfs() {
    int sz[3] = {int(v[0].size()), int(v[1].size()), int(v[2].size())};
    if (sz[2] == n) return;
    if (!sz[0] && !sz[1]) throw 1;
    //error check
    for (int i = 1; i < sz[1]; i++) {
        if (v[1][i-1]+1 < v[1][i]) {
            throw 1;
        }
    }

    //v[1] have maximum?
    int m = 0;
    for (int d: v[1]) {
        m = max(m, d);
    }
    if (m == up) {
        int c = 0;
        while (v[1][c] != up) c++;
        move(1, c+1);
        up -= c+1;
        dfs();
        return;
    }

    int mi = v[0][0], ma = v[0][0];
    bool di = false;
    int co = 0;
    int r = sz[0];
    int fr = -1;
    for (int i = 1; i < sz[0]; i++) {
        if (v[0][i-1]+1 < v[0][i]) {
            r = i;
            break;
        }
        if (v[0][i-1] > v[0][i]) {
            if (fr == -1) {
                fr = i;
            }
            co++;
        }
        mi = min(mi, v[0][i]);
        ma = max(ma, v[0][i]);
    }
    co++;
    if (co == 1) {
        fr = r;
    }
    //printf("mi %d ma %d co %d fr %d r %d\n", mi, ma, co, fr, r);
    //maximum(corner case)
    if (ma == up) {
        move(0, 1);
        dfs();
        return;
    }
    //combine
    if (sz[1] && mi < v[1][0]) {
        int c = 0;
        while (c < r && v[0][c] != v[1][0]-1) {
            c++;
        }
        if (v[0][c] == v[1][0]-1) c++;
        move(0, c);
        dfs();
        return;
    }
    //all move
    if (ma-mi+1 != r) {
        move(0, r);
        dfs();
        return;
    }
    
    int u = (ma-m);
    if (co >= 3) {
        if (u <= B[1] || /*B[0] < r ||*/ r <= min(B[0], B[1])) {
            move(0, fr);
        } else {
            move(0, r);
        }
        dfs();
        return;
    }

    //single
    if (fr <= B[0] && r-fr <= B[0] && u <= B[1]) {
        move(0, fr);
        dfs();
        return;
    }

    //single single
    if (co == 1) {
        if (fr <= min(B[1], B[0])) {
            move(0, fr);
        } else {
            move(0, 1);
        }
        dfs();
        return;
    }

    //co == 2
    int bi = m + B[1];
    if (r-fr < B[1]) {
        move(0, min(B[0], min(fr, B[1]-(r-fr))));
        dfs();
        return;
    }
    if (r-fr == B[1] && r <= B[0]) {
        move(0, r);
        dfs();
        return;
    }
    move(0, min(B[0], fr + B[1]));
    dfs();
    return;
}

int main() {
    //freopen("tmp.txt", "r", stdin);
    cin >> n >> B[0] >> B[1]; up = n;
    //n = 2000; B[0] = B[1] = 1; up = n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[0].push_back(x);
    }

    try {
        dfs();
        cout << "YES" << endl;
        cout << que.size() << endl;
        for (auto p: que) {
            cout << p.first << " " << p.second << endl; 
        }
    } catch(int a) {
        cout << "NO" << endl;
    }
    return 0;
}