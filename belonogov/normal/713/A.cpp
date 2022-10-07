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

#define equal equalll
#define less lesss
const int N = 1e6;
const long long INF = 1e9 + 19;

char s[100];
int cnt[N];

void read() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char ch;
        scanf(" %c %s", &ch, s);
        int len = strlen(s);
        int mask = 0;
        for (int j = 0; j < len; j++) {
            if ((s[len - j - 1] - '0') % 2)
                mask |= (1 << j);
        }
        if (ch == '+') 
            cnt[mask]++;
        if (ch == '-') 
            cnt[mask]--;
        if (ch == '?') 
            printf("%d\n",cnt[mask]);
    }

}

void solve() {

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
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