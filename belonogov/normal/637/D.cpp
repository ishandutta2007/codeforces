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
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;

int n, m, s, d;
int a[N];

void read() {
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
}

vector < pair < int, int > > answer; 

bool solve() {
    sort(a, a + n);
    a[n] = m + s + 2;
    
    int prev = 0;
    for (int i = 0; i < n;) {
        //db2(prev, i);
        if (a[i] - 1 - prev < s) return 0;
                
        answer.pb(mp(0, a[i] - 1 - prev));
        prev = a[i] - 1;

        int j = i;
        for (; a[i + 1] - a[i] - 2 < s; i++);
        //db2(i);
        
        if (a[i] - a[j] + 2 > d) return 0;

        answer.pb(mp(1, a[i] + 1 - prev));

        prev = a[i] + 1;

        i++;
    }

    if (prev < m) 
        answer.pb(mp(0, m - prev));

    return 1;

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
            bool res = solve();
            if (res) {
                for (auto x: answer) {
                    if (x.fr == 0)
                        printf("RUN ");
                    else
                        printf("JUMP ");
                    printf("%d\n", x.sc);
                } 
            }
            else 
                puts("IMPOSSIBLE");
        }
    }
    else {
        stress();
    }

    return 0;
}