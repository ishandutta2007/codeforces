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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

#define equal equalll
#define less lesss
const int N = 1e6 + 100;
const int INF = 1e9;

int n, k;
char s[N];
int z[N];

void read() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
}

void z_f() {
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (r > i) 
            z[i] = min(z[i - l], r - i);
        for (; i + z[i] < n && s[z[i]] == s[i + z[i]]; z[i]++);
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
}

void solve() {
    if (k == 1) {
        for (int i = 0; i < n; i++)
            printf("1");
        printf("\n");
        return;
    }
    z_f();
    //for (int i = 0; i < n; i++)
        //cerr << z[i] << " ";
    //cerr << endl;
    vector < pair < int, int > > event;
    for (int i = 0; i < n; i++) {
        if (i * 1ll * k > n) continue;
        int l = i * k;
        int r = i * (k + 1); 
        r = min(r, i + z[i]);
        if (l <= r) {
            //cerr << "l r: " << l << " " << r << endl;
            event.pb(mp(l, 1));
            event.pb(mp(r + 1, -1));
        }
    }
    sort(event.begin(), event.end());
    vector < int > answer;
    int cnt = 0;
    int cur = 0;
    for (int i = 1; i < n + 1; i++) {
        for (; cur < (int)event.size() && event[cur].fr <= i; cur++) {
            cnt += event[cur].sc; 
        }
        answer.pb(cnt > 0);
    }
    for (auto x: answer)
        printf("%d", x);
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
        for (int tt = 0; tt < 1; tt++) {
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