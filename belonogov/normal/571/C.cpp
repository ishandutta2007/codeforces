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
#define where whereree

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const int INF = 1e9 + 19;

int n, m;
vector < int > e[N];
vector < pair < int, int > > where[N];
int answer[N];
bool use[N];
set < int > who[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        e[i].resize(k);
        for (int j = 0; j < k; j++)
            scanf("%d", &e[i][j]);
    }
}

int sign(int x) {
    assert(x != 0);
    if (x < 0) return 0;
    return 1;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (auto x: e[i])
            where[abs(x) - 1].pb(mp(i, sign(x)));
    }  
    memset(answer, -1, sizeof(answer));    
    for (int i = 0; i < m; i++) {
        if (where[i].empty()) {
            answer[i] = 0;
            continue;
        }
        assert((int)where[i].size() <= 2);
        if (where[i][0].sc == where[i].back().sc) {
            for (auto x: where[i]) {
                answer[i] = x.sc;
                use[x.fr] = 1;
            }
        }
    }
    //db("here");
    set < pair < int, int > > q;
    for (int i = 0; i < n; i++) {
        if (use[i]) continue;
        for (auto x: e[i])
            who[i].insert(abs(x) - 1); 
        q.insert(mp(who[i].size(), i));
    }    
    
    //db(q.size());
   
   
    while (!q.empty()) {
        int v = q.begin()->sc;
        q.erase(q.begin());
        //db(q.size());
        //cerr << "========\n"; 
       //db(v);
        //for (int i = 0; i < n; i++) {
            //db(i);
            //for (auto x: who[i])
                //cerr << x << " ";
            //cerr << endl;
        //}
        //cerr << "========\n"; 

        if (who[v].empty()) {
            puts("NO");
            return;
        }
        int var = *who[v].begin();
        int type = -1;
        //db(var);
        for (auto x: where[var])
            if (x.fr == v) {
                assert(type == -1);
                type = x.sc;
            }
            else {
                if (!use[x.fr]) {
                    q.erase(mp(who[x.fr].size(), x.fr));
                    assert(who[x.fr].count(var) == 1);
                    who[x.fr].erase(var); 
                    q.insert(mp(who[x.fr].size(), x.fr));
                }
            }
        assert(type != -1);
        answer[var] = type;
        use[v] = 1;
    }
    puts("YES");
    for (int i = 0; i < m; i++) {
        if (answer[i] == -1)
            answer[i] = 0;
        printf("%d", answer[i]);
    }
    printf("\n");


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