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
const int N = 2e6 + 10;
const long long INF = 1e9 + 19;

int n;
int use[N];
int pref[N];
int mx;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mx = max(mx, x);
        use[x] = 1;
    }
}

int getSum(int l, int r) {
    return pref[r] - pref[l];
}

void solve() {
    for (int i = 0; i < mx * 2; i++)
        pref[i + 1] = pref[i] + use[i];
    int answer = 0;
    for (int i = 1; i <= mx; i++) {
        if (use[i]) {
            for (int k = 1; k * i <= mx; k++) {
                for (; getSum(k * i + answer + 1, (k + 1) * i) > 0; answer++);
            }
        }


    }
    cout << answer << endl;




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