#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define lSon (node << 1)
#define rSon (lSon | 1)

const int maxN = 200011;

struct rect {
    int x1, y1, x2, y2;
};

bool removed[maxN], selected[maxN];

struct aint {
    int mini[maxN * 4 + 11];
    int best[maxN * 4 + 11];
    priority_queue<int> col[4 * maxN + 11];
    priority_queue<int> unsel[4 * maxN + 11];

    void clr(priority_queue<int>& data) {
        while (!data.empty()) data.pop();
    }

    void build(int node, int l, int r) {
        best[node] = -1;
        clr(col[node]); clr(unsel[node]);
        col[node].push(0);
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);
    }

    void recomp(int node, int l, int r) {
        while (!col[node].empty()) {
            if (!removed[col[node].top()]) break;
            col[node].pop();
        } 
        if (col[node].empty()) cerr << "Error: col 0 dis\n";

        while (!unsel[node].empty()) {
            if (!selected[unsel[node].top()]) break;
            unsel[node].pop();
        }

        //if (node == 4 && unsel[node].empty() == false)
        //    cerr << unsel[node].top() << "??\n";

        int maxi;
        maxi = mini[node] = col[node].top();
        best[node] = (unsel[node].empty() ? -1 : unsel[node].top());
        if (best[node] < maxi) best[node] = -1;
        if (l == r) return;

        int mid = (l + r) >> 1;
        mini[node] = max(maxi, min(mini[lSon], mini[rSon]));
        best[node] = max(best[node], max(best[lSon], best[rSon]));
        if (mini[node] > best[node]) best[node] = -1;
    }

    void upd(int node, int l, int r, int qL, int qR, int v) {
        //cerr << "!" << node << ' ' << qL << ' ' << qR << '\n';

        if (qL <= l && r <= qR) {
            if (v != -1) {
                col[node].push(v);
                if (!selected[v]) unsel[node].push(v);
            }
            recomp(node, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) upd(lSon, l, mid, qL, qR, v);
        if (qR > mid) upd(rSon, mid + 1, r, qL, qR, v);
        recomp(node, l, r);
    }
};

struct event {
    int y, x1, x2, tp;
    
    bool operator<(const event& who)const {
        return y < who.y;
    }
};

int n, i, j, ans;
rect R[maxN];
vector<int> xx, yy;
aint work;
int cnt_x, cnt_y;
vector<event> E;

void modif(int &v, vector<int>& data) {
    v = lower_bound(data.begin(), data.end(), v) - data.begin() + 1;
}

void norm() {
    int i;
    
    sort(xx.begin(), xx.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
    sort(yy.begin(), yy.end());
    yy.resize(unique(yy.begin(), yy.end()) - yy.begin());

    for (i = 1; i <= n; i++) {
        modif(R[i].x1, xx);
        modif(R[i].x2, xx);
        modif(R[i].y1, yy);
        modif(R[i].y2, yy);

        //cerr << R[i].x1 << ' ' << R[i].y1 << ' ';
        //cerr << R[i].x2 << ' ' << R[i].y2 << '\n';
    }
}

void execute(event act) {
    //cerr << "Executing : " << act.y << ' ' << act.x1 << ' ' << act.x2 << ' ' << act.tp << "\n";

    if (act.tp > 0) {
        work.upd(1, 1, cnt_x, act.x1, act.x2 - 1, act.tp);
    } else {
        removed[-act.tp] = selected[-act.tp] = true;
        work.upd(1, 1, cnt_x, act.x1, act.x2 - 1, -1);
    }
}

int main()
{
//    freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &R[i].x1, &R[i].y1, &R[i].x2, &R[i].y2);
        xx.pb(R[i].x1);
        xx.pb(R[i].x2);
        yy.pb(R[i].y1);
        yy.pb(R[i].y2);
    }

    norm();
    cnt_x = xx.size();
    cnt_y = yy.size();
    for (i = 1; i <= n; i++) {
        E.pb({R[i].y1, R[i].x1, R[i].x2, +i});
        E.pb({R[i].y2, R[i].x1, R[i].x2, -i});
    }
    sort(E.begin(), E.end());
    selected[0] = true;
    work.build(1, 1, cnt_x);

    for (i = 0; i < E.size(); i = j) {
        for (j = i; j < E.size(); j++) {
            if (E[i].y != E[j].y) break;
            execute(E[j]);
        }


        while (work.best[1] != -1) {
            int id = work.best[1];
            
            selected[id] = true;
            ans++;

            //cerr << "HERE " << id << '\n';
            work.upd(1, 1, cnt_x, R[id].x1, R[id].x2 - 1, -1);

            //for (int p = 1; p <= 5; p++) cerr << work.best[p] << ' ';
            //cerr << '\n';
        }
    }

    //cerr << "END------------------\n";
    printf("%d", ans + 1);

    return 0;
}