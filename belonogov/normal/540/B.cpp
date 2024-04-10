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
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = 1e5;
const int INF = 1e9;

int n, k, p, x, y;
int a[N];
int b[N];

void read() {
    cin >> n >> k >> p >> x >> y;
    for (int i = 0; i < k; i++)
        cin >> a[i];
}

void solve() {  
    int cnt = (n + 1) / 2; 
    for (int i = 0; i < k; i++)
        cnt -= (a[i] >= y);
    cnt = max(0, cnt);
    
    for (int i = 0; i < cnt; i++) 
        a[k + i] = y;

    for (int i = k + cnt; i < n; i++)
        a[i] = 1;

}

void printAns() {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    if (sum > x) 
        printf("-1\n");
    else {
        sort(a, a + n);
        if (a[n / 2] < y) printf("-1\n");
        else {
            for (int i = k; i < n; i++)
                printf("%d ", b[i]);
            printf("\n");
        }

    }



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