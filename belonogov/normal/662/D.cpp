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
const int N = 1100;
const long long INF = 1e9 + 19;

int n;
char t[100];
char s[N];

void read() {
    fgets(t, N, stdin);
    sscanf(t, "IAO'%s", s);
}

void solve() {
    int len = strlen(s);
    //cerr << "t: " << t << endl;
    //db2(len, s);
    //cerr << "s: " << s << endl;
    //db(s);
    long long id = 1988;
    long long x = 0;
    long long g = 1;
    for (int i = len - 1; i >= 0; i--) {
        x += (s[i] - '0') * g;
        long long step = g;
        g *= 10;
        id += step;
        for (; id % g != x; id += step);
    }
    printf("%lld\n", id);

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k;
        scanf("%d", &k);
        fgets(s, N, stdin);
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