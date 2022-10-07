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

int n, x, y, l;
int a[N];
set < int > q;

void read() {
    scanf("%d%d%d%d", &n, &l, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        q.insert(a[i]);
    }
}

void solve() {
    bool flagX = 0;
    bool flagY = 0;
    for (int i = 0; i < n; i++) {
        flagX |= q.count(a[i] + x) == 1;
        flagY |= q.count(a[i] + y) == 1;
    }
    //db2(flagX, flagY);
    if (flagX && flagY) {
        puts("0");
        return;
    } 
    if (flagX || flagY) {
        printf("1\n%d\n", (!flagX) * x + (!flagY) * y);
        return;
    } 
    for (int i = 0; i < n; i++) {
        for (int t = -1; t <= 1; t += 2) {
            int tmp = a[i] + t * x;
            //db(tmp);
            if (0 <= tmp && tmp <= l && (q.count(tmp + y) == 1 || q.count(tmp - y) == 1))  {
                printf("1\n%d\n", tmp); 
                return;
            }
        }
    } 
    printf("2\n%d %d\n", x, y);






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