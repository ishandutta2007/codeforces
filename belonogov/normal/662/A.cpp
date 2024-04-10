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
const int N = 62;
const long long INF = 1e9 + 19;
const int M = 555000;

int n;
long long a[M];
bitset < M > b[N];
long long res = 0;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        res ^= x;
        a[i] = y ^ x;
        //db(i);
    }
}

long long solve() {
    
    //db("here");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++)
            b[j][i] = (a[i] >> j) & 1;
    }      
    for (int j = 0; j < N; j++)
        b[j][n] = (res >> j) & 1;
    
    //db("here");

    int cur = 0; 
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = cur; j < N; j++)    
            if (b[j][i] == 1) {
                pos = j;
                break;
            }
        if (pos == -1) continue;
        
        swap(b[cur], b[pos]);    
        for (int j = 0; j < N; j++) {
            if (j == cur) continue;
            if (b[j][i]) {
                b[j] ^= b[cur];
            } 
        }
        cur++;
    }
    //for (int i = 0; i < 10; i++, cerr << endl)
        //for (int j = 0; j < 10; j++)
            //cerr << b[i][j] << " ";
    //db(cur);
    for (int i = cur; i < N; i++)
        if (b[i][n]) {
            return -1;
        } 
    return cur;
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
            int cnt = solve();
            if (cnt == -1) {
                puts("1/1");
                return 0;
            }
            long long res = (1ll << cnt);
            printf("%lld/%lld\n", res - 1, res);
        }
    }
    else {
        stress();
    }

    return 0;
}