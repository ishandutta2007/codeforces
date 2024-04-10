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
const int N = -1;
const int INF = 1e9;

int a[100];

void read() {
    int n;
    scanf("%d", &n);
    int cur = 0;
    for (; n > 0; n /= 10, cur++) {
        a[cur] = n % 10;
    }
    vector < int > ans;
    
    for (;;) {
        int x = 0;
        int deg = 1;
        for (int i = 0; i < cur; i++) {
            if (a[i] > 0) {
                a[i]--;
                x += deg;
            }
            deg *= 10;
        }
        if (x == 0) break;
        ans.pb(x);
    }
    cout << ans.size() << endl;
    for (auto x: ans)
        cout << x << " ";
    cout << endl;

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