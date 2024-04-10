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
const int N = 2e5 + 10;
const int INF = 1e9;

int n, m;
pair < int, int > c[N];
int x[N];
int p[N];
int stack[N];




int findNext(int t, int l, int type) {  /// r == 0 l == 1
    t += (type == 0)? l: -l;
    //db2(t, type);
    //db2(t, l);
    if (type == 0) {
        int it = upper_bound(x, x + n, t) - x;
        it--;
        assert(it >= 0);
        return it;
    }
    else {
        int it = lower_bound(x, x + n, t) - x; 
        assert(it < n);
        return it;
    }
}

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i].fr);
        c[i].sc = i;
    }
    sort(c, c + n);
    for (int i = 0; i < n; i++)
       p[c[i].sc] = i; 
    for (int i = 0; i < n; i++)
        x[i] = c[i].fr;

    for (int tt = 0; tt < m; tt++) {
        int pos, l;
        scanf("%d%d", &pos, &l); pos--;
        pos = p[pos];
        //int cur = 0;
        //stack[cur++] = pos; 
        //db(pos);
        int prev = -1;
        int cnt = 0;
        for (int type = 0;; type ^= 1) {
            //db("here");

            int id = findNext(x[pos], l, type); 
            //db2(id, l);
            int len = abs(x[id] - x[pos]);
            assert(len <= l);
           //db2(len, pos);
            if (len == 0) 
                cnt++;
            if (cnt >= 3) break;
            //db2(
            if (len > 0 && prev == id) {
                l %= (2 * len);
            }
            if (l < len) continue;
            l -= len;
            prev = pos;
            pos = id;
        }
        //db(pos);
        printf("%d\n", c[pos].sc + 1);
    }


}

void solve() {

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
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