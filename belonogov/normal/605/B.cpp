#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;

struct Edge {
    int id, v, u, cost, type;
};

int n, m;
Edge e[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &e[i].cost, &e[i].type);
        e[i].id = i;
    }
}

bool cmpE(Edge a, Edge b) {
    return a.cost < b.cost || (a.cost == b.cost && a.type > b.type);
}

bool cmpId(Edge a, Edge b) {
    return a.id < b.id;
}

void solve() {
    sort(e, e + m, cmpE);
    int curV = 1;
    int cur1 = 2;
    int cur2 = 0;
    for (int i = 0; i < m; i++) {
        if (e[i].type == 1) {
            e[i].v = curV - 1;
            e[i].u = curV;
            curV++;
        }
        if (e[i].type == 0) {
            if (cur1 >= curV) {
                puts("-1");
                return;
            }
            e[i].v = cur1;
            e[i].u = cur2;
            cur2++;
            if (cur2 == cur1 - 1) {
                cur2 = 0;
                cur1++;
            }
        }
    }
    sort(e, e + m, cmpId);
    for (int i = 0; i < m; i++)
        printf("%d %d\n", e[i].v + 1, e[i].u + 1);

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}