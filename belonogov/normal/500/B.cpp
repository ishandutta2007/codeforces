#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) { cerr << #x << " = " << x << endl; }
const int N = 1000;
const int INF = 1e9;

int n;
int a[N];
int p[N];
char s[N][N];
int answer[N];
vector < int > e[N];
vector < int > pos[N];

void merge(int v, int u) {
    p[v] = u;
}

int getId(int v) {
    return (p[v] == v)? v : p[v] = getId(p[v]);
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
}

void solve() {
    for (int i = 0; i < n; i++)
       p[i] = i; 
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i][j] == '1') {
                int v = getId(i);
                int u = getId(j);
                merge(v, u);
            }
    for (int i = 0; i < n; i++) {
        int type = getId(i);
        //cerr << "type: " << type << endl;
        e[type].pb(a[i]);
        pos[type].pb(i);
    }
    for (int i = 0; i < n; i++) {
        sort(e[i].begin(), e[i].end());
        sort(pos[i].begin(), pos[i].end());
    }
    memset(answer, -1, sizeof(answer));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (int)e[i].size(); j++)
            answer[pos[i][j]] = e[i][j];
    for (int i = 0; i < n; i++)
        printf("%d ", answer[i]);
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
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}