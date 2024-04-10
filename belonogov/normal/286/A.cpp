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

int n;

void read() {
    scanf("%d", &n);
    if (n % 4 == 1 || n % 4 == 0) {
        int g = n - n % 4;
        vector < int > tmp(g);
        for (int i = 0; i < g / 2; i += 2) {
            int a = i;
            int b = i + 1;
            int a1 = g - a - 1;
            int b1 = g - b - 1;
            tmp[i] = b;
            tmp[i + 1] = a1;
            tmp[g - b - 1] = a;
            tmp[g - a - 1] =  b1;
        }
        if (n % 4 == 1) {
            for (int i = 0; i < g; i++)
                tmp[i] += tmp[i] >= g / 2;
            tmp.insert(tmp.begin() + g / 2, g / 2);
        }
        for (int i = 0; i < n; i++)
            printf("%d ", tmp[i] + 1);
        puts("");
    }
    else {
        puts("-1");
    }
}

void solve() {

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
        }
    }
    else {
        stress();
    }

    return 0;
}