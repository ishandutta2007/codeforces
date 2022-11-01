#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int n;
vector <int> a;
vector <int> g[101000];

int pos = 0;

void printerr() {
    printf("Error occurred\n");
    exit(0);
}

int go() {
    if (pos == a.size())
        printerr();
    
    int cur = pos;
    if (a[cur] == 0) {
        ++pos;
        g[cur].pb(go());
        g[cur].pb(go());
        return cur;
    }
    else {
        ++pos;
        return pos - 1;
    }
}

void dfs(int v) {
    if (a[v] == 1) {
        printf("int");
        return;
    }
    printf("pair<");
    dfs(g[v][0]);
    printf(",");
    dfs(g[v][1]);
    printf(">");
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    string s;
    while (cin >> s) {
        if (s == "pair")
            a.pb(0);
        else a.pb(1);
    }
    int res = go();
    if (pos != a.size())
        printerr();
    dfs(res);
    return 0;
}