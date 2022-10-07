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
const int N = 100000;
const int INF = 1e9;

int n;
char s[N];

void read() {
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++) {
        for (int shift = 1; shift < n; shift++) {
            bool flag = 1;
            for (int j = 0; j < 5; j++)
                flag &= i + shift * j < n && s[i + shift * j] == '*';
            if (flag) {
                printf("yes\n");
                return;
            }
        }
    }
    printf("no\n");
}

void solve() {

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