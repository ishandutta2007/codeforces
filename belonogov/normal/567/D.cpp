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
const int N = -1;
const int INF = 1e9 + 19;

int n, k, a, m;

int f(int len) {
    len++;
    return len / (a + 1);
}

void read() {
    scanf("%d%d%d%d", &n, &k, &a, &m);
    int cnt = f(n);
    assert(cnt >= k);
    set < int > q;
    q.insert(-1);
    q.insert(n);
    for (int i = 0; i < m; i++) {
        int x; 
        scanf("%d", &x);
        x--;
        auto it = q.lower_bound(x); 
        int r = *it;
        assert(it != q.begin());
        it--;
        int l = *it;
        cnt -= f(r - l - 1);
        q.insert(x);
        //cerr << "l x r: " << l << " " << x << " " << r << endl;
        //db(cnt);
        
        cnt += f(x - l - 1);
        cnt += f(r - x - 1);
        //db(cnt);

        if (cnt < k) {
            printf("%d\n", i + 1);
            return;
        }
    }
    puts("-1");
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