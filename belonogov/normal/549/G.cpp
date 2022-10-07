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

#define equal equalll
#define less lesss
const int N = 1e6;
const int INF = 1e9;


int n;
int a[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]); 
}

void solve() {
    for (int i = 0; i < n; i++)
        a[i] += i;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        a[i] -= i; 
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1]) {
            cout << ":(\n";
            return;
        }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
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