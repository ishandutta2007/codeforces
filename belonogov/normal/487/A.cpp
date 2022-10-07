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
const int N = -1;
const int INF = 1e9 + 19;



int h1, a1, d1;
int h2, a2, d2;
int h, a, d;


void read() {
    scanf("%d%d%d", &h1, &a1, &d1);
    scanf("%d%d%d", &h2, &a2, &d2);
    scanf("%d%d%d", &h, &a, &d);
}
int answer = INF;

void upd(int x, int y, int z) {
    answer = min(answer, x * h + y * a + z * d);
}

void solve() { 
    for (int i = 0; i <= 200; i++)
        for (int j = 0; j <= 100; j++) {
            if (i + a1 <= d2) continue;         
            if (j + d1 >= a2) {
                upd(0, i, j);
            }
            else {
                int speed1 = a1 + i - d2;
                int speed2 = a2 - j - d1;
                int alife = (h2 + speed1 - 1) / speed1;
                int need =  alife * speed2 + 1;
                int dop = max(0, need - h1);
                upd(dop, i, j);
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