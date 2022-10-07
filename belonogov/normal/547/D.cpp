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

#define equal equalll
#define less lesss
const int N = 1e6;
const int INF = 1e9;

int n; 
pair < int, int > p[N];
map < pair < int, int >, int > q;
multiset < pair < int, int > > e[N];
int answer[N];
int cur;

int getId(pair < int, int > t) {
    if (q.count(t) == 0) {
        q[t] = cur++;
    }
    return q[t];
}

void read() {
    scanf("%d", &n); 
    for (int i = 0; i < n; i++)
        scanf("%d%d", &p[i].fr, &p[i].sc);
}

void go(int v, int color) {
    if (e[v].empty()) {
        return;
    } 
    auto x = *(e[v].begin());
    
    int id = x.sc;
    int u = x.fr;
    answer[id] = color;
    e[v].erase(e[v].begin());
    e[u].erase(mp(v, id));
    go(u, color ^ 1);
}

void solve() {
    cur = 0;
    q.clear();
    for (int i = 0; i < n * 2; i++)
        e[i].clear();
    for (int i = 0; i < n; i++) {
        int v = getId(mp(p[i].fr, 1));
        int u = getId(mp(p[i].sc, 2));
        e[v].insert(mp(u, i));
        e[u].insert(mp(v, i));
    } 

    memset(answer, -1, sizeof(answer));
    for (int i = 0; i < cur; i++) {
        for (int j = 0; !e[i].empty(); j++) {
            //db2(i, j % 2);
            go(i, j % 2);
        }
    }



    for (int i = 0; i < n; i++) {
        assert(answer[i] != -1);
        if (answer[i] == 0) 
            printf("b");
        else
            printf("r");
    }
    printf("\n");
}

void printAns() {

}

void stress() {
    for (int tt = 0; ; tt++) {
        cerr << "test id: " << tt << endl;
        n = 20;
        int T = 10;
        for (int i = 0; i < n; i++)
            p[i] = mp(rand() % T, rand() % T);
        solve();
        vector < int > count(cur); 
        for (int i = 0; i < n; i++) {
            int x = answer[i];
            if (x == 0) x = -1;
            count[getId(mp(p[i].fr, 1))] += x;
        }
        for (int i = 0; i < cur; i++)
            assert(abs(count[i]) <= 1);
        //for (int i = 0; i < cur; i++)
            //cerr << count[i] << " ";
        //cerr << endl;






    }


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