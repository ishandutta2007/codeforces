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
const int N = 3333;
const long long INF = 1e9 + 19;

int n;
int a[N];
int cnt[N];
int ver[N];
int c[N];
pair < int, int > b[N];
int tmr = 1;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

}

void get(int x) {
    if (ver[x] != tmr) {
        ver[x] = tmr;
        cnt[x] = 0;
    }
    cnt[x]++;
}

struct CMP {
    bool operator ()(pair < int, int >  a, pair < int, int >  b) {
        return a.fr < b.fr;
    }
};

void solve() {
    sort(a, a + n);
    int cur = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < n && a[i] == a[j]; i++);
        b[cur++] = mp(a[j], i - j);
    }
    //for (int i = 0; i < cur; i++)
        //db2(b[i].fr, b[i].sc);
    int answer = 0;
    for (int i = 0; i < cur; i++)
        for (int j = 0; j < cur; j++) {
            tmr++;
            get(i);
            get(j);     
            if (cnt[i] > b[i].sc) continue;
            c[0] = b[i].fr;
            c[1] = b[j].fr; 
            for (int t = 2; ; t++) {
                if (t > answer) {
                    answer = t;
                    //db2(b[i].fr, b[j].fr);
                }
                int x = c[t - 1] + c[t - 2];
                int pos = lower_bound(b, b + cur, mp(x, -1), CMP()) - b;
                if (pos == cur || b[pos].fr != x)
                    break;
                get(pos);
                if (cnt[pos] > b[pos].sc) break;
                c[t] = x;
            }

        }

    printf("%d\n", answer);


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
        }
    }
    else {
        stress();
    }

    return 0;
}