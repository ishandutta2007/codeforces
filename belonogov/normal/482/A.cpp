#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = -1;
const int INF = 1e9;

int n, k;

void read() {
    scanf("%d%d", &n, &k);
}

void solve() {
    //k--;
    ///printf("1 ");
    int curUp = n;
    int curDown = 1;
    int k0 = k;
    for (int i = 0;k; i++, k--) {
        if (i % 2 == 0) {
            printf("%d ", curDown);
            curDown++;
        }
        else {
            printf("%d ", curUp);
            curUp--;
        }
    }
    k = k0;
    if (k % 2 == 0) {
        for (; k < n; k++) {
            printf("%d ", curUp);
            curUp--;
        }
    }
    else {
        for (; k < n; k++) {
            printf("%d ", curDown);
            curDown++;
        }

    }
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
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}