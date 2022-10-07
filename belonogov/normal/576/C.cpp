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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6;
const int INF = 1e9 + 19;
const int T = 1e3;

struct pnt {
    int x, y, id;
};

int n;
pnt b[N];
vector < pnt > c[T + 10];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &b[i].x, &b[i].y);
        b[i].id = i;
    }
}

bool cmpY(const pnt & a, const pnt & b) {
    return a.y < b.y;
}

void solve() {
    for (int i = 0; i < n; i++)
        c[b[i].x / T].pb(b[i]); 

    vector < int > answer;
    for (int i = 0; i <= T; i++) {
        sort(c[i].begin(), c[i].end(), cmpY);
        if (i % 2 == 1) {
            reverse(all(c[i]));
        }
        for (auto x: c[i])
            answer.pb(x.id);
    }
    for (auto x: answer)
        printf("%d ", x + 1);
    puts("");

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