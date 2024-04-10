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
const int N = -1;
const long long INF = 1e9 + 19;


int n, k;


int getF(int x) {
    if (k == 0) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (x == 2) return 2;
        return x % 2 == 0;
    }    
    else {
        assert(k == 1);
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (x == 2) return 0;
        if (x == 3) return 1;
        if (x == 4) return 2;

        if (x % 2 == 1) return 0; 
        int r = getF(x / 2);
        if (r == 1) return 2;
        return 1;
    }

}

int dp[1000];

void read() {
    //dp[0] = 0;
    //int n = 100;
    //k = 0;
    //for (int i = 1; i < n; i++) {
        //set < int > q;
        //q.insert(dp[i - 1]);
        //if (i % 2 == 0) q.insert(0);
        //int r = 0;
        //for (; q.count(r) == 1; r++);
        //dp[i] = r;
        //cerr << "i f r: " << i << " " << getF(i) << " " << r << endl;
        //assert(getF(i) == r);
    //}

    //for (int i = 0; i < 20; i++)
        //db2(i, getF(i));
    //exit(0);

    


    scanf("%d%d", &n, &k);
    k %= 2;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        res ^= getF(x);
    }
    if (res == 0) 
        puts("Nicky");
    else
        puts("Kevin");

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