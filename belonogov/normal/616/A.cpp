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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

char s[N];
char t[N];

void read() {
    scanf("%s%s", s, t);
}

void solve() {
    int n, m;
    n = strlen(s);
    m = strlen(t);
    int curS = 0;
    int curT = 0;
    for (; s[curS] == '0'; curS++);
    for (; t[curT] == '0'; curT++);

    if (n - curS != m - curT) {
        if (n - curS > m - curT)
            puts(">");
        else
            puts("<");
        return;
    }

    int len = n - curS;
    for (int i = 0; i < len; i++) {
        if (s[i + curS] != t[i + curT]) {
            if (s[i + curS] > t[i + curT])
                puts(">");
            else
                puts("<");
            return;
        }
    }
    puts("=");

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