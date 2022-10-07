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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;

int n;
int y[N];
int x[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &y[i]);
}


bool check(int bound) {
    map<int,int> q;
    for (int i = 0; i < n; i++) {
        int x = y[i];
        for (; x > bound; x /= 2);
        q[x]++;
    }
    int cur = 0;
    while (!q.empty()) {
        auto p = *q.rbegin(); 
        //db2(p.fr, p.sc);
        assert(p.sc > 0);
        if (p.fr == 0) {
            return 0;
        }
        x[cur++] = p.fr;
        p.sc--;
        if (p.sc > 0)
            q[p.fr / 2] += p.sc;
        q.erase(p.fr);
    }
    //db("tut");

    assert(cur == n);
    return 1;
}


void solve() {
    int l = 0; 
    int r = INF;
    //check(6);
    //return;
    while (r - l > 1) {
        if (check((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    //db2(l, r);
    assert(check(r));

    for (int i = 0; i < n; i++)
        printf("%d ", x[i]);
    puts("");
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;

}

void stress() {

}

int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    freopen("test.txt", "r", stdin);
    freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}