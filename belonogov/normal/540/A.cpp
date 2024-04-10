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

char s[N];
char t[N];

void read() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    int sum = 0;
    for (int i = 0; i < n; i++) {       
        int x = min(s[i] - '0', t[i] - '0');
        int y = max(s[i] - '0', t[i] - '0');
        sum += min(y - x, x + 10 - y);
    }
    cout << sum << endl;
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