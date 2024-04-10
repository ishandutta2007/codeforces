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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 2e6 + 10;
const int INF = 1e9 + 19;

int n;
int a[N];

void read() {
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
        mx = max(mx, x);
    }
    int answer = 0;
    for (int i = 0; i < mx + 100; i++) {
        if (a[i] % 2 == 1) {
            answer++;
            a[i]--;
        }
        a[i + 1] += a[i] / 2;
    }
    cout << answer << endl;

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