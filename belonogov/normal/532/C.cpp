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
const int N = -1;
const int INF = 1e9;

string P = "Polycarp";
string V = "Vasiliy";

void read() {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int t1 = x1 + y1;
    int t2 = max(x2, y2);
    if (x2 >= x1 && y2 >= y1) {
        cout << P << endl;
        return;
    }


    if (t1 <= t2) {
        cout << P << endl;
    }
    else
        cout << V << endl;
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