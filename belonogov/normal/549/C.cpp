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
const int N = -1;
const int INF = 1e9;

int n, k;
int cnt[2];

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x % 2]++; 
    }
}

void ret(int x) {
    assert(x == 1 || x == 2);
    if (x == 1)
        cout << "Stannis\n";
    else
        cout << "Daenerys\n";
    exit(0);
}

void solve() {
    int d = n - k;
    int stepC = (d + 1) / 2; 
    int stepD = d / 2;
    if (n == k) {
        if (cnt[1] % 2 == 1)
            ret(1);
        ret(2);
    }
    if (d % 2 == 0) {  // last D 
        if (k % 2 == 1 && cnt[0] <= stepC) 
            ret(1);
        else
            ret(2);
    }  
    else {     // last C
        if (cnt[1] <= stepD) ret(2);
        if (cnt[0] <= stepD && k % 2 == 0) ret(2);
        ret(1);
    }


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